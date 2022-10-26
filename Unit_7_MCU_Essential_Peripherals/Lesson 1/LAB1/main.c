/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
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
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

#define RCC_BASE 	0x40021000
#define RCC_AHBENR *((unsigned int*)(RCC_BASE+0x14))
// GPIOA Register
#define GPIOA_BASE 	0x40010800
#define GPIOA_CRL *((unsigned int*)(GPIOA_BASE+0x00))
#define GPIOA_CRH *((unsigned int*)(GPIOA_BASE+0x04))
#define GPIOA_IDR *((unsigned int*)(GPIOA_BASE+0x08))
#define GPIOA_ODR *((unsigned int*)(GPIOA_BASE+0x0c))
// GPIOB Register
#define GPIOB_BASE  0x40010c00
#define GPIOB_CRL *((unsigned int*)(GPIOB_BASE+0x00))
#define GPIOB_CRH *((unsigned int*)(GPIOB_BASE+0x04))
#define GPIOB_IDR *((unsigned int*)(GPIOB_BASE+0x08))
#define GPIOB_ODR *((unsigned int*)(GPIOB_BASE+0x0c))

void clock_int()
{
	// Enable GPIOA Clock
	RCC_AHBENR |= 1<<2 ;
	// Enable GPIOB Clock
	RCC_AHBENR |= 1<<3 ;
}

void GPIO_int()
{
	GPIOA_CRL = 0x00 ;
	GPIOB_CRL = 0x00 ;
	//Port A->1 Floating Input
	GPIOA_CRL &= ~(0b11<<4) ;
	GPIOA_CRL |=  (0b01<<6) ;

	//Port B->1 Output
	GPIOB_CRL |= (0b01<<4) ;
	GPIOB_CRL |= (0b00<<6) ;

	//Port A->13 Flaoting Input
	GPIOA_CRH &= ~(0b1111<<20);
	GPIOA_CRH |=  (0b0100<<20) ;

	//Port B->13 Output
	GPIOB_CRH &= ~(0b1111<<20);
	GPIOB_CRH |=  (0b0001<<4) ;
}

void main ()
{
	int i ;
	clock_int();
	GPIO_int();

	GPIOB_ODR = 0x00 ;
	while(1)
	{
		if((GPIOB_IDR & (1<<1)>>1)==0)
		{
			GPIOB_ODR ^= (1<<1) ;
			while((GPIOB_IDR & (1<<1)>>1)==0);
		}

		if((GPIOB_IDR & (1<<13)>>13)==1)
		{
			GPIOB_ODR ^= (1<<3) ;
			for (i = 0 ; i < 10000 ; i ++);
		}
	}
}
