/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void MUSART1_vidInit(void);
void MUSART1_vidTransmitChar  ( u8   Copy_u8Char    );
void MUSART1_vidTransmitString( u8 * Copy_ptrString );
void MUSART1_vidSetCallBack( void (* ptrFunc )(void));
u8   MUSART1_u8ReceiveChar( void );
void MUSART1_vidNewLine   ( void );

void MUSART1_vidClearFlag(void);


void MUSART2_vidInit(void);
void MUSART2_vidTransmitChar  ( u8   Copy_u8Char    );
void MUSART2_vidTransmitString( u8 * Copy_ptrString );
void MUSART2_vidSetCallBack( void (* ptrFunc )(void));
u8   MUSART2_u8ReceiveChar( void );
void MUSART2_vidNewLine   ( void );

void MUSART2_vidClearFlag(void);

#endif /* USART_INTERFACE_H_ */
