/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "STM32F103Cx6.h"
#include "Stm32_F103C6_GPIO_drivers.h"

void clock_int()
{
	// Enable GPIOA Clock
	RCC_GPIOA_CLK_EN();
	// Enable GPIOB Clock
	RCC_GPIOB_CLK_EN();
}

void GPIO_int()
{
	GPIO_PinConfig_t Pincg ;
//	//Port A->1 Floating Input
//	Pincg.GPIO_Mode = GPIO_Mode_Input_FLO ;
//	Pincg.GPIO_PinNumber = GPIO_Pin_1 ;
//	MCAL_GPIO_Init(GPIOA, &Pincg);
//
	//Port B->1 Output
	Pincg.GPIO_Mode = GPIO_Mode_Output_AF_PP ;
	Pincg.GPIO_PinNumber = GPIO_Pin_1 ;
	Pincg.GPIO_Output_Speed = GPIO_Speed_10M ;
	MCAL_GPIO_Init(GPIOB, &Pincg);
//
//	//Port A->13 Flaoting Input
//	Pincg.GPIO_Mode = GPIO_Mode_Input_FLO ;
//	Pincg.GPIO_PinNumber = GPIO_Pin_13 ;
//	MCAL_GPIO_Init(GPIOA, &Pincg);
//
//	//Port B->13 Output
//	Pincg.GPIO_Mode = GPIO_Mode_Output_AF_PP ;
//	Pincg.GPIO_PinNumber = GPIO_Pin_13 ;
//	Pincg.GPIO_Output_Speed = GPIO_Speed_10M ;
//	MCAL_GPIO_Init(GPIOB, &Pincg);
}

int main ()
{
	int i ;
	clock_int();
	GPIO_int();

	while(1)
	{
		MCAL_GPIO_WritePin(GPIOB,GPIO_Pin_1,1);
//		if(MCAL_GPIO_ReadPin(GPIOA,GPIO_Pin_1)==0)
//		{
//			MCAL_GPIO_TogglePin(GPIOB, GPIO_Pin_1);
//			while(MCAL_GPIO_ReadPin(GPIOA,GPIO_Pin_1)==0);
//		}
//
//		if(MCAL_GPIO_ReadPin(GPIOA,GPIO_Pin_13)==1)
//		{
//			MCAL_GPIO_TogglePin(GPIOB, GPIO_Pin_13);
//			for (i = 0 ; i < 10000 ; i ++);
//		}
	}
}
