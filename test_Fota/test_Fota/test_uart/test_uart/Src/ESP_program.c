/****************************************************************/
/* Author    : Ahmed Khaled                                      */
/* Date      : 28 SEP 2020                                      */
/* Version   : V01                                              */
/****************************************************************/


#include "TYPES.h"
#include "MACROS.h"

#include "MSTK_Interface.h"
#include "USART_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "NVIC_INTERFACE.h"

#include "ESP_interface.h"


/* Buffer To Receive Data */
volatile u8 RealData[MAX_LINES][MAX_CHARS];

/* Record line */
volatile u8 Global_u8Line = 0;



void ESP8266_voidInit(void)
{


		/* Sending AT Command To Check ESP8266 Is Working Or Not  */
		MUSART1_vidTransmitString( (u8 *)"AT\r\n")
		MSTK_voidSetBusyWait( 1000 *1000);

		/* Close ESP8266 Echo */
		MUSART1_vidTransmitString( (u8 *)"ATE0\r\n");
		MSTK_voidSetBusyWait( 3000 *2000);


		/* Set The Station Mode  */
		//MUSART1_vidTransmitString( (u8 *)"AT+CWMODE=1\r\n");
		//MSTK_voidSetBusyWait( 3000 *2000);

}


void ESP8266_voidConnectToWiFi ( u8 * SSID , u8 * Password )
{

	MUSART1_vidTransmitString( (u8 *) "AT+CWJAP_CUR=\"" );
	MUSART1_vidTransmitString( (u8 *) SSID );
	MUSART1_vidTransmitString( (u8 *) "\",\"" );
	MUSART1_vidTransmitString( (u8 *) Password);
	MUSART1_vidTransmitString( (u8 *) "\"\r\n");
	MSTK_voidSetBusyWait(  3000 *2000);
	MSTK_voidSetBusyWait(  3000 *2000);
	MSTK_voidSetBusyWait(  3000 *2000);

}


void ESP8266_voidConnectToServerTcp ( u8 * Copy_u8Domain , u8 * Copy_u8Port ){


/*   this command setup TCP connection */
	MUSART1_vidTransmitString( (u8 *) "AT+CIPSTART=\"TCP\",\"" );
	MUSART1_vidTransmitString( (u8 *) Copy_u8Domain );
	MUSART1_vidTransmitString( (u8 *) "\"," );
	MUSART1_vidTransmitString( (u8 *) Copy_u8Port );
	MUSART1_vidTransmitString( (u8 *) "\r\n" );
	MSTK_voidSetBusyWait( 2000 *2000);

}


u8 ESP8266_u8ReceiveHttpReq(u8 *Copy_u8Server, u8 *Copy_u8FilePath, u8 *Copy_u8Length) {
    u8 Local_u8Receive = 0;

    /* Sending IP Length */
    MUSART1_vidTransmitString((u8 *)"AT+CIPSEND=");
    MUSART1_vidTransmitString((u8 *)Copy_u8Length);
    MUSART1_vidTransmitString((u8 *)"\r\n");
    MSTK_voidSetBusyWait(4000 * 2000);

    /* Getting Data */
    MUSART1_vidTransmitString((u8 *)"GET http://");
    MUSART1_vidTransmitString((u8 *)Copy_u8Server);
    MUSART1_vidTransmitString((u8 *)Copy_u8FilePath);
    MUSART1_vidTransmitString((u8 *)"\r\n");
    MSTK_voidSetBusyWait(40000 * 2000);

    ESP8266_voidConnectToServerTcp((u8 *)Copy_u8Server, (u8 *)"80");

    /* Setting CallBack Function */
    MUSART1_CallBack( ESP8266_MUSART1CallBackFunction() );

    /* Enabling USART1 Interrupt To Start Receiving Data */
    MNVIC_VidEnablePeripheral(USART1);

    return Local_u8Receive;
}


static u8 voidEspValidateCmd(void)
{
	u8 i = 0;
	u8 Dummy = 0;
	u8 Result = 0;
	u8 Loc_u8CharCount=0;
	
	while (Dummy != 255)
	{
		Dummy = MUSART1_u8RecCharSynch();
		Global_u8Response[i] = Dummy;
		i++;
	}
	
	/* Check if Ok */
	if (Global_u8Response[0] == 'O' && Global_u8Response[1] == 'K')
	{
		Result = 1;
	}
	
	return Result;
}

/* Receive one full record and */
void ESP8266_voidReceiveRecord (void)
{

	static  u8 Loc_u8StartRecord_Flag = 0;
	static  u8 Loc_u8StartData_Flag   = 0;
	u8 Loc_u8Char 			  = 0;
	u8 Loc_u8Data			  = 0;
	u8 Loc_u8CharCount=0;


	while(Loc_u8Data != '\n')
	{
		Loc_u8Data = MUSART1_u8ReceiveChar();

		//Check  '+' in  "+IPD,Size :"
		if(  ( Loc_u8Data == '+') )
		{
			Loc_u8StartRecord_Flag = 0 ;
			Loc_u8StartData_Flag   = 0 ;
		}
		//Check second ':'  "Related To Received Record"
		else if(  ( Loc_u8Data == ':') )
		{
			Loc_u8StartRecord_Flag = 1 ;
		}
		else if(Loc_u8StartRecord_Flag ==1)
		{
			Loc_u8StartData_Flag = 1 ;
		}


		if( Loc_u8StartData_Flag == 1 && Loc_u8Data != '\r')
		{

			//Save Allowed Data From Record
			RealData[Global_u8Line][Loc_u8Char] = Loc_u8Data;

			Loc_u8Char++;

			//Check The End Of Record
			if(Loc_u8Data == '\n')
			{
				Loc_u8StartData_Flag   = 0;
				Loc_u8Char = 0;
				Global_u8Line++;
			}

		}
	}
}

/* Filling RealData buffer with the records lines till the max line */
void ESP8266_MUSART1CallBackFunction(void)
{
	u8 Loc_u8EndOfFileflag = 0, Loc_u8CharCount = 0, Loc_u8LineCount = 0;

	/* Receiving Record By Record */
	ESP8266_voidReceiveRecord();

	/* Check if buffer line less than the max lines of the buffer */
	if(Global_u8Line < MAX_LINES-1 )
	{
		/* check if it's the last record by checking if record type byte = 1 */
		if (RealData[Global_u8Line][8] == '1' )
		{
			Loc_u8EndOfFileflag = 1;

			/* put two F in the last two bytes of the last record */
			RealData[Global_u8Line][9] =  'F';
			RealData[Global_u8Line][10] = 'F';
		}
	}
	else
	{
		/* Send  All Data In Buffer By Sending Record By Record */
		for(Loc_u8LineCount = 0 ;Loc_u8LineCount <= Global_u8Line; Loc_u8LineCount++)
		{
			/* Sending record till it's end */
			for(Loc_u8CharCount = 0;	 Loc_u8CharCount < MAX_CHARS ;Loc_u8CharCount++)
			{
				/* Sending data in buffer through TX2 to Target board */
				MUSART2_VidSendCharSync( RealData[Loc_u8LineCount][Loc_u8CharCount] );

				/* break when reaching the record's end*/
				if(RealData[Loc_u8LineCount][Loc_u8CharCount] == '\n')
				{
					break;
				}
			}

			 /* waiting for acknowledgment through RX2 from Target Board */
			while(MUSART2_u8RecCharSynch() != 'K');
		}

		/* clear buffer to start from line zero */
		Global_u8Line = 0;

		//couter ++;
	}
	while(Loc_u8EndOfFileflag != 1);
}



