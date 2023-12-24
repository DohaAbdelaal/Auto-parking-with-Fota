/*
 * GLB_Decleration.h
 * 		Created on: Dec 13, 2022
 *  	Author: NTI-G6-TeamA
 */


/*******************************************************************************************************/
/*                            guard of file will call one time in .c file	                           */
/*******************************************************************************************************/
#ifndef GLB_DECLARATIONS_H_
#define GLB_DECLARATIONS_H_

#include "ABL_Private.h"

/*variable to indicate the time out of the systick peripheral*/
volatile u8 TimeOutFlag = APP_VALUE_0 ;
/* the buffer that will receive the data from UART*/
 u8 ReceiveBuffer[BUFFER_INDEX] ;
/*the receive counter*/
volatile u8 u8RecCounter = APP_VALUE_0 ;
/*the write request to write in the flash*/
volatile u8 u8WriteReq = APP_VALUE_1  ;

typedef void (*APP_Call)(void) ;
/*pointer to pointer to function that will be assigned the address of application to run*/
APP_Call Add_To_Call = APP_VALUE_0 ;
u8 rec_flag=0;


#endif /* GLB_DECLARATIONS_H_ */
