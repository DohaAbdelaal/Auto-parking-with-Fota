/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/


#include "TYPES.h"
#include "MACROS.h"

#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "NVIC_INTERFACE.h"
#include "USART_INTERFACE.h"
#include "MSTK_Interface.h"
#include "ESP_interface.h"

void func(void);

//extern u8 RealData[MAX_LINES][MAX_CHARS];
//extern volatile u8 Global_u8Line;

int main(void)
{


	/* Enable Clock For Peripherals */
	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock ( APB2_BUS , GPIOA_RCC                   ) ;

	MRCC_VidEnablePeripheralClock ( APB2_BUS , USART1_RCC                  ) ;
	MRCC_VidEnablePeripheralClock ( APB1_BUS , USART2_RCC                  ) ;

	/* Init USART1 (to WIFI module (ESP8266))	 */
	MGPIO_VidSetPinDirection      ( GPIOA , PIN9  , OUTPUT_SPEED_2MHZ_AFPP ) ;
	MGPIO_VidSetPinDirection      ( GPIOA , PIN10  , INPUT_FLOATING ) ;
	MUSART1_vidInit();

	/* Init USART2 (To Target Controller (STM32)) */
	MGPIO_VidSetPinDirection      ( GPIOA , PIN2  , OUTPUT_SPEED_2MHZ_AFPP ) ;
	MGPIO_VidSetPinDirection      ( GPIOA , PIN3  , INPUT_FLOATING ) ;
	MUSART2_vidInit();

	/* Init WIFI Module */
	ESP8266_voidInit();

	/* Connecting  WIFI Module to Internet */
	ESP8266_voidConnectToWiFi((u8 *)"DESKTOP-MD95H9O",(u8 *)"123123123");

	/* Connecting  WIFI Module to Server */
	ESP8266_voidConnectToServerTcp((u8 *)"69.197.143.14",(u8 *)"80");

	/* Getting The Uploaded firmware from Server */
	ESP8266_u8ReceiveHttpReq((u8 *)"fota-mmm.freevar.com/",(u8 *) "uploads/upload1.txt",(u8 *) "62"); //move inside (do while)


	while(1)
	{
	}

	return 0;

}



