/*
 * Stm32F103Cx6.h
 *
 *  Created on: Nov 30, 2022
 *      Author: Abdullah Kortam
 */

#ifndef INC_STM32F103CX6_H_
#define INC_STM32F103CX6_H_

//---------------------------------------
//includes
//---------------------------------------
#include "stdlib.h"
#include <stdint.h>

//---------------------------------------
//Base addresses for Memories
//---------------------------------------
#define FLASH_MEMORY_BASE   			0x08000000UL
#define SRAM_MEMORY_BASE				0x20000000UL
#define SYSTEM_MEMORY_BASE 				0x1FFFF000UL

#define PERIPHERALS_BASE 				0x40000000UL
#define CORTEX_M3_INTERNAL_PERIPHERALS  0xE0000000UL

//---------------------------------------
//Base addresses for AHP Peripherals
//---------------------------------------
//RCC
#define RCC_BASE     (PERIPHERALS_BASE + 0x00021000UL)

//---------------------------------------
//Base addresses for APB2 Peripherals
//---------------------------------------
//GPIO
// A,B Fully included in LQFP48 Package
#define GPIOA_BASE    (PERIPHERALS_BASE + 0x00010800UL)
#define GPIOB_BASE    (PERIPHERALS_BASE + 0x00010C00UL)
// C,D Partial included in LQFP48 Package
#define GPIOC_BASE    (PERIPHERALS_BASE + 0x00011000UL)
#define GPIOD_BASE    (PERIPHERALS_BASE + 0x00011400UL)
//E not included in LQFP48 Package
#define GPIOE_BASE    (PERIPHERALS_BASE + 0x00011800UL)

//EXTI
#define EXTI_BASE    (PERIPHERALS_BASE + 0x00010400UL)

//AFIO
#define AFIO_BASE    (PERIPHERALS_BASE + 0x00010000UL)

//=================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register : GPIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CRL ;
	volatile uint32_t CRH ;
	volatile uint32_t IDR ;
	volatile uint32_t ODR ;
	volatile uint32_t BSRR ;
	volatile uint32_t BRR ;
	volatile uint32_t LCKR ;
}GPIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register : RCC
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBRSTR;
	volatile uint32_t CFGR2;
}RCC_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register : EXTI
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register : AFIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	uint32_t RESERVED1;
	volatile uint32_t MAPR2;
}AFIO_TypeDef;

//=================================================================================

//---------------------------------------
//Peripheral Instants:
//---------------------------------------
//GPIO
#define GPIOA		((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB		((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC		((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD		((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE		((GPIO_TypeDef *)GPIOE_BASE)

//RCC
#define RCC			((RCC_TypeDef *)RCC_BASE)
//EXTI
#define EXTI 		((EXTI_TyoeDef *)EXTI_BASE)
//AFIO
#define AFIO		((AFIO_TypeDef *)AFIO_BASE)

//==================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Clock Enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define RCC_GPIOA_CLK_EN() (RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN() (RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN() (RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN() (RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN() (RCC->APB2ENR |= 1<<6)

#define RCC_AFIO_CLK_EN() (RCC->APB2ENR |= 1<<0)
#endif /* INC_STM32F103CX6_H_ */
