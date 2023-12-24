/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#ifndef USART_REG_H_
#define USART_REG_H_

typedef struct
{

	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;

}USART_Type;


#define MUSART1 ( ( volatile USART_Type* ) 0x40013800 )

#define MUSART2 ( ( volatile USART_Type* ) 0x40004400 )

#define MUSART3 ( ( volatile USART_Type* ) 0x40004800 )

#define MUSART4 ( ( volatile USART_Type* ) 0x40004C00 )

#define MUSART5 ( ( volatile USART_Type* ) 0x40005000 )


#define WORD_LENGTH_8BIT        0
#define WORD_LENGTH_9BIT        1


#define PARITY_DISABLE          0
#define EVEN_PARITY             1
#define ODD_PARITY              2


#define TX_DISABLE              0
#define TX_ENABLE               1


#define RX_DISBLE               0
#define RX_ENABLE               1


#define ONE_STOP_BIT            0
#define TWO_STOP_BIT            1


#define POLLING_BASED           0
#define TXE_INT_ENABLE          1
#define TCE_INT_ENABLE          3
#define RXNE_INT_ENABLE         5





#endif /* USART_REG_H_ */
