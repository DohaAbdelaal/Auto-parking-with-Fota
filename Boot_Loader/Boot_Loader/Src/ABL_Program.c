/*
 * ABL_Program.c
 * 		Created on: Dec 13, 2022
 *  	Author: NTI-G6-TeamA
 */


/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/
#include "LSTD_TYPES.h"
#include "GLB_Declarations.h"


/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/

#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"
#include "MUSART_Interface.h"
#include "MFDI_Interface.h"
#include "MSTK_Config.h"
#include "ABL_Private.h"
#include "APARSER_Interface.h"


void ABL_VoidInit(void)
{
	/*initializing the system clock as configured in the CNFG file*/
	MRCC_voidInitSystemClk();
	/*enable the clock for GPIOA Peripheral*/
	MRCC_voidEnablePeripheralClock(AHB1,MRCC_PERIPHERAL_EN_GPIOA);
	/*enable the clock for USART1 Peripheral*/
	MRCC_voidEnablePeripheralClock(APB2,MRCC_PERIPHERAL_EN_USART1);
	/*enable the clock for flash driver peripheral*/
	MRCC_voidEnablePeripheralClock(AHB1LP,MRCC_PERIPHERAL_EN_FDI);
	/*set the alternative function of pin 9*/
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN9,MGPIO_MODE_ALTF) ;
	/*set the alternative function to pin 10*/
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN10,MGPIO_MODE_ALTF) ;
	/*initialing the USART Peripheral*/
	MUSART_voidInit();
	/*enable the UART Peripheral*/
	MUSART_voidEnable();
	/*enable the systick peripheral*/
	MSTK_voidInit();
	/*waiting to receive the application through UART, if not no application will run*/
	MSTK_voidSetIntervalSingle(NUMBER_OF_TICKS,ABL_VoidJumptoApp);

}
void ABL_VoidRun(void)
{
	/*STATUS VARIABLE FOR RECEIVEING*/
	u8 LOC_u8RecStatus=APP_VALUE_0;
	/*LOOP TIL HEX FILE IS RECEIVED OR STK TIME HAS EXCEEDED*/
	while(TimeOutFlag == APP_VALUE_0)
	{
		/*reading data from UART*/
		LOC_u8RecStatus = MUSART_u8ReadDataSynch(&ReceiveBuffer[u8RecCounter]) ;
		if(LOC_u8RecStatus == APP_VALUE_1)
		{
			/*Stop Timer Because Application Code In Processing*/
			MSTK_voidInit();
			/*indicate The end Of the Record*/
			if(ReceiveBuffer[u8RecCounter] == '\0')
			{
				/*erasing the memory for the first time*/
				if(u8WriteReq == APP_VALUE_1)
				{
					/*set this led to low to indicate the flashing is started*/
					MGPIO_voidSetPinValue(MGPIOA_PORT,MGPIO_PIN12,MGPIO_LOW);
					/*Erase The Application Code*/
					MFDI_voidEraseAppArea() ;
					/*setting this variable to 1 to avoid erase memory again*/
					u8WriteReq =APP_VALUE_0 ;
				}
				/*Parse The Record and Write it to flash*/
				APARSER_voidParseRecord(ReceiveBuffer) ;
				/*Reset Buffer Counter*/
				u8RecCounter = APP_VALUE_0 ;
			}
			else{u8RecCounter++ ; }

			/*End Of File*/
			if(ReceiveBuffer[APP_VALUE_8] == '1')
			{
				/*Wait 1 second then jump to Application*/
				MSTK_voidSetIntervalSingle(MSTK_ONE_SECOND,ABL_VoidJumptoApp) ;
			}


		}


	}
}

void ABL_VoidJumptoApp(void)
{
	/*setting the time out flag to 1 to avoid entering the super loop*/
	TimeOutFlag = 1 ;
	/*Move Vector Table*/
#define SCB_VTOR       *((volatile u32*)0xE000ED08)

	SCB_VTOR = 0x08001000 ; //Starting of Sector 1 [Application]

	/*Set Address to call with Reset Handeler_ISR [startup code of Application]*/
	Add_To_Call = *(APP_Call*) 0x08001004 ;

	Add_To_Call() ; //jump Reset handler [startup code]
}
