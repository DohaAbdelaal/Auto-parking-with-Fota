/*
 * main.c
 * 		Created on: Dec 13, 2022
 *  	Author: NTI-G6-TeamA
 *

 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	/*call the function to init the application*/
	ABL_VoidInit();
	/*call function to run the application*/
	ABL_VoidRun();
}
