/*
 * APARSER_Interface.h
 * 		Created on: Dec 13, 2022
 *  	Author: NTI-G6-TeamA
 */


/*******************************************************************************************************/
/*                            guard of file will call one time in .c file	                           */
/*******************************************************************************************************/
#ifndef APARSER_INTERFACE_H_
#define APARSER_INTERFACE_H_

u8 APARSER_u8AsciiToHex(u8 Copy_u8Asci) ;



void APARSER_voidParseRecord(u8 * Copy_u8BufRecord) ;




void APARSE_voidParseData(u8* Copy_u8BufData) ;

#endif /* APARSER_INTERFACE_H_ */
