/*
 * MFDI_Interface.h
 * 		Created on: Dec 13, 2022
 *  	Author: NTI-G6-TeamA
 */


/*******************************************************************************************************/
/*                            guard of file will call one time in .c file	                           */
/*******************************************************************************************************/

#ifndef MFDI_INTERFACE_H_
#define MFDI_INTERFACE_H_

void MFDI_voidEraseAppArea(void) ;
void MFDI_voidFlashWrite(u32 Copy_u32Address ,u16* Copy_PtrData, u8 Copy_u8DataLength) ;
void MFDI_voidSectorErase(u8 Copy_u8SectorNumber) ;



#endif /* MFDI_INTERFACE_H_ */
