/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#include "TYPES.h"
#include "MACROS.h"

#include "USART_INTERFACE.h"
#include "USART_CONFIG.h"
#include "USART_REG.h"

void(*MUSART1_CallBack)(void);

void MUSART1_vidInit(void)
{

	MUSART1 -> SR = 0 ;

	MUSART1 -> BRR = 0x45 ;

	/*             Word Length Of Data             */
	#if   USART1_WORD_LENGTH == WORD_LENGTH_8BIT

		CLR_BIT( MUSART1 -> CR1 , 12 );

	#elif USART1_WORD_LENGTH == WORD_LENGTH_9BIT

		SET_BIT( MUSART1 -> CR1 , 12 );

	#endif

	/*             Parity Bit                      */
	#if   USART1_PARITY == PARITY_DISABLE

		CLR_BIT( MUSART1 -> CR1 , 10 );

	#elif USART1_PARITY == EVEN_PARITY

		SET_BIT( MUSART1 -> CR1 , 10 );
		CLR_BIT( MUSART1 -> CR1 , 11 );

    #elif USART1_PARITY == ODD_PARITY

		SET_BIT( MUSART1 -> CR1 , 10 );
		SET_BIT( MUSART1 -> CR1 , 11 );

	#endif


	/*               TX Enable                    */
	#if   USART1_TX_STATUS == TX_ENABLE

		SET_BIT( MUSART1 -> CR1 , 3 );

	#elif USART1_TX_STATUS == TX_DISABLE

		CLR_BIT( MUSART1 -> CR1 , 3 );

	#endif



	/*               RX Enable                    */
	#if   USART1_RX_STATUS == RX_ENABLE

		SET_BIT( MUSART1 -> CR1 , 2 );

	#elif USART1_RX_STATUS == RX_DISABLE

		CLR_BIT( MUSART1 -> CR1 , 2 );

	#endif



    /*       Configure Number Of Stop Bit         */
	#if   USART1_STOP_BITS == ONE_STOP_BIT

		CLR_BIT( MUSART1 -> CR2 , 12 );
		CLR_BIT( MUSART1 -> CR2 , 13 );

	#elif USART1_STOP_BITS == TWO_STOP_BIT

		CLR_BIT( MUSART1 -> CR2 , 12 );
		SET_BIT( MUSART1 -> CR2 , 13 );


	#endif

	#if  USART1_INTERRUPT_STATE == POLLING_BASED

			CLR_BIT( MUSART1 -> CR1 , 5 );
			CLR_BIT( MUSART1 -> CR1 , 6 );
			CLR_BIT( MUSART1 -> CR1 , 7 );

	#elif USART1_INTERRUPT_STATE == TXE_INT_ENABLE

			SET_BIT( MUSART1 -> CR1 , 7 );

	#elif USART1_INTERRUPT_STATE == TCE_INT_ENABLE

			SET_BIT( MUSART1 -> CR1 , 6 );

	#elif USART1_INTERRUPT_STATE == RXNE_INT_ENABLE

			SET_BIT( MUSART1 -> CR1 , 5 );

	#endif


	/*       Calculate Mantissa and Fraction       */
/*	f32 Local_f32Mantissa = (   F_CPU   ) / (   16 * USART1_BAUD_RATE   ) ;

	u8  Local_u8Fraction  = ( Local_f32Mantissa - (u32)Local_f32Mantissa) * 16 ;

	if(Local_u8Fraction > 15 )
	{
		Local_f32Mantissa += 1 ;
		Local_u8Fraction   = 0 ;
	}*/




	/*             Enable USART                    */
	SET_BIT( MUSART1 -> CR1 , 13 );


}


void MUSART1_vidTransmitChar  ( u8   Copy_u8Char    )
{

	MUSART1 -> DR = Copy_u8Char ;

	while( GET_BIT( MUSART1 -> SR , 6 ) == 0 );

//	CLR_BIT( MUSART1 -> SR , 6 );

}


void MUSART1_vidTransmitString( u8 * Copy_ptrString )
{

	u8 Local_u8Counter = 0 ;

	while ( Copy_ptrString[ Local_u8Counter ] != '\0' )
	{

		MUSART1_vidTransmitChar( Copy_ptrString[ Local_u8Counter ] );
		Local_u8Counter++ ;

	}

}


u8   MUSART1_u8ReceiveChar( void )
{
	u8  Local_u8Data  = 0 ;

	#if USART1_INTERRUPT_STATE == POLLING_BASED
		CLR_BIT ( MUSART1 -> SR, 5);

		while( ( GET_BIT ( MUSART1 -> SR, 5) == 0 ));

		Local_u8Data = MUSART1 -> DR;
		return Local_u8Data;

	#elif  USART1_INTERRUPT_STATE == RXNE_INT_ENABLE
		Local_u8Data = MUSART1 -> DR;
		return Local_u8Data;

	#endif

}


void MUSART1_vidNewLine   ( void )
{
	MUSART1_vidTransmitChar('\n');
	MUSART1_vidTransmitChar('\r');
}


void MUSART1_vidSetCallBack( void(*ptrFunc)(void) )
{

	MUSART1_CallBack = ptrFunc ;

}

void MUSART1_vidClearFlag(void)
{
	MUSART1 -> SR = 0 ;
}


void USART1_IRQHandler(void)
{
	MUSART1_CallBack();
}







void(*MUSART2_CallBack)(void);

void MUSART2_vidInit(void)
{

	MUSART2 -> SR = 0 ;

	MUSART2 -> BRR = 0x45 ;

	/*             Word Length Of Data             */
	#if   USART2_WORD_LENGTH == WORD_LENGTH_8BIT

		CLR_BIT( MUSART2 -> CR1 , 12 );

	#elif USART2_WORD_LENGTH == WORD_LENGTH_9BIT

		SET_BIT( MUSART2 -> CR1 , 12 );

	#endif

	/*             Parity Bit                      */
	#if   USART2_PARITY == PARITY_DISABLE

		CLR_BIT( MUSART2 -> CR1 , 10 );

	#elif USART2_PARITY == EVEN_PARITY

		SET_BIT( MUSART2 -> CR1 , 10 );
		CLR_BIT( MUSART2 -> CR1 , 11 );

    #elif USART2_PARITY == ODD_PARITY

		SET_BIT( MUSART2 -> CR1 , 10 );
		SET_BIT( MUSART2 -> CR1 , 11 );

	#endif


	/*               TX Enable                    */
	#if   USART2_TX_STATUS == TX_ENABLE

		SET_BIT( MUSART2 -> CR1 , 3 );

	#elif USART2_TX_STATUS == TX_DISABLE

		CLR_BIT( MUSART2 -> CR1 , 3 );

	#endif



	/*               RX Enable                    */
	#if   USART2_RX_STATUS == RX_ENABLE

		SET_BIT( MUSART2 -> CR1 , 2 );

	#elif USART2_RX_STATUS == RX_DISABLE

		CLR_BIT( MUSART2 -> CR1 , 2 );

	#endif



    /*       Configure Number Of Stop Bit         */
	#if   USART2_STOP_BITS == ONE_STOP_BIT

		CLR_BIT( MUSART2 -> CR2 , 12 );
		CLR_BIT( MUSART2 -> CR2 , 13 );

	#elif USART2_STOP_BITS == TWO_STOP_BIT

		CLR_BIT( MUSART2 -> CR2 , 12 );
		SET_BIT( MUSART2 -> CR2 , 13 );


	#endif

	#if  USART2_INTERRUPT_STATE == POLLING_BASED

			CLR_BIT( MUSART2 -> CR1 , 5 );
			CLR_BIT( MUSART2 -> CR1 , 6 );
			CLR_BIT( MUSART2 -> CR1 , 7 );

	#elif USART2_INTERRUPT_STATE == TXE_INT_ENABLE

			SET_BIT( MUSART2 -> CR1 , 7 );

	#elif USART2_INTERRUPT_STATE == TCE_INT_ENABLE

			SET_BIT( MUSART2 -> CR1 , 6 );

	#elif USART2_INTERRUPT_STATE == RXNE_INT_ENABLE

			SET_BIT( MUSART2 -> CR1 , 5 );

	#endif


	/*       Calculate Mantissa and Fraction       */
/*	f32 Local_f32Mantissa = (   F_CPU   ) / (   16 * USART1_BAUD_RATE   ) ;

	u8  Local_u8Fraction  = ( Local_f32Mantissa - (u32)Local_f32Mantissa) * 16 ;

	if(Local_u8Fraction > 15 )
	{
		Local_f32Mantissa += 1 ;
		Local_u8Fraction   = 0 ;
	}*/




	/*             Enable USART                    */
	SET_BIT( MUSART2 -> CR1 , 13 );
	MUSART2 -> SR=0;
	MUSART2 -> DR =0;

}


void MUSART2_vidTransmitChar  ( u8   Copy_u8Char    )
{


	MUSART2 -> DR = Copy_u8Char ;

	while( GET_BIT( MUSART2 -> SR , 6 ) == 0 );

//	CLR_BIT( MUSART2 -> SR , 6 );

}


void MUSART2_vidTransmitString( u8 * Copy_ptrString )
{

	u8 Local_u8Counter = 0 ;

	while ( Copy_ptrString[ Local_u8Counter ] != '\0' )
	{

		MUSART2_vidTransmitChar( Copy_ptrString[ Local_u8Counter ] );
		Local_u8Counter++ ;

	}

}


u8   MUSART2_u8ReceiveChar( void )
{
	u8  Local_u8Data  = 0 ;

	#if USART1_INTERRUPT_STATE == POLLING_BASED
		CLR_BIT ( MUSART2 -> SR, 5);

		while( ( GET_BIT ( MUSART2 -> SR, 5) == 0 ));

		Local_u8Data = MUSART2 -> DR;
		return Local_u8Data;

	#elif  USART1_INTERRUPT_STATE == RXNE_INT_ENABLE
		Local_u8Data = MUSART2 -> DR;
		return Local_u8Data;

	#endif

}


void MUSART2_vidNewLine   ( void )
{
	MUSART2_vidTransmitChar('\n');
	MUSART2_vidTransmitChar('\r');
}


void MUSART2_vidSetCallBack( void(*ptrFunc)(void) )
{

	MUSART2_CallBack = ptrFunc ;

}

void MUSART2_vidClearFlag(void)
{
	MUSART2 -> SR = 0 ;
}


void USART2_IRQHandler(void)
{
	MUSART2_CallBack();
}

