/*
 * ABL_Interface.h
 * 		Created on: Dec 13, 2022
 *  	Author: NTI-G6-TeamA
 */


/*******************************************************************************************************/
/*                            guard of file will call one time in .c file	                           */
/*******************************************************************************************************/
#ifndef BL_INTERFACE_H_
#define BL_INTERFACE_H_

/*function to initializing the bootloader application*/
void ABL_VoidInit(void);
/*function to run the bootloader application*/
void ABL_VoidRun(void);


#endif /* BL_INTERFACE_H_ */
