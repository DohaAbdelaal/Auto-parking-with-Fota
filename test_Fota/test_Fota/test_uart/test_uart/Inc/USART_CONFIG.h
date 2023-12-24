/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/* System Clock */



#define F_CPU                    8000000UL

#define USART1_BAUD_RATE         (u32)115200

#define USART1_WORD_LENGTH       WORD_LENGTH_8BIT

#define USART1_PARITY            PARITY_DISABLE
#define USART1_STOP_BITS         ONE_STOP_BIT

#define USART1_TX_STATUS         TX_ENABLE
#define USART1_RX_STATUS         RX_ENABLE

#define USART1_INTERRUPT_STATE   RXNE_INT_ENABLE




#define USART2_BAUD_RATE         (u32)115200

#define USART2_WORD_LENGTH       WORD_LENGTH_8BIT

#define USART2_PARITY            PARITY_DISABLE
#define USART2_STOP_BITS         ONE_STOP_BIT

#define USART2_TX_STATUS         TX_ENABLE
#define USART2_RX_STATUS         RX_ENABLE

#define USART2_INTERRUPT_STATE   RXNE_INT_ENABLE


#endif /* USART_CONFIG_H_ */
