/*
 * MNVIC_Interface.h
 * 		Created on: Dec 13, 2022
 *  	Author: NTI-G6-TeamA
 */


/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


typedef enum
{
  MNVIC_GROUPMODE_G16S0 = 3 ,
  MNVIC_GROUPMODE_G8S2      ,
  MNVIC_GROUPMODE_G4S4      ,
  MNVIC_GROUPMODE_G2S8      ,
  MNVIC_GROUPMODE_G0S16
}MNVIC_GroupMode_t;

/*#####################################################################################################*/
/*                                      Function Prototypes                                            */
/*#####################################################################################################*/


void MNVIC_voidEnableInterrupt(u8 Copy_u8IntPos) ;
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntPos) ;
void MNVIC_voidEnableInterruptPending  (u8 Copy_u8IntPos) ;
void MNVIC_voidDisableInterruptPending  (u8 Copy_u8IntPos) ;
u8 MNVIC_u8IsInterruptActive (u8 Copy_u8IntPos) ;
void MNVIC_voidSetInterruptPriority  (u8 Copy_u8IntPos ,MNVIC_GroupMode_t Copy_uddtGroupMode,u8 Copy_u8GroupNum,u8 Copy_u8SubGroupNum ) ;
void MNVIC_voidSetInterruptGroupMode(MNVIC_GroupMode_t Copy_uddtGroupMode) ;





#endif //NVIC_INTERFACE_H
