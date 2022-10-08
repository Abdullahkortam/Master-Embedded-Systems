/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

// register address
#define GPIO_BASE 0x40010800
#define RCC_BASE  0x40021000

#define GPIO_ODR *(volatile int*)(GPIO_BASE + 0x0C)
#define GPIO_CRH *(volatile int*)(GPIO_BASE + 0x04)

#define RCC_APB2EN *(volatile int*)(RCC_BASE + 0x18)
#define RCC_CFGR *(volatile int*)(RCC_BASE + 0x04)
#define RCC_CR *(volatile int*)(RCC_BASE)

int main(void)
{
	RCC_APB2EN |= 1<<2 ;
	RCC_CFGR |= 0b100<<8 ;
	RCC_CFGR |= 0b101<<11 ;
	RCC_CFGR |= 0b110<<18 ;
	RCC_CFGR |= 0b10<<0;
    RCC_CR|=1<<24 ;

	//Init GPIOA
	GPIO_CRH &=0xff0fffff;
	GPIO_CRH |=0x00200000;
    /* Loop forever */
	while(1)
	{
		GPIO_ODR |= 1<13 ;
		for(int i=0;i<5000;i++);

		GPIO_ODR &=~(1<13) ;
		for(int i=0;i<5000;i++);
	}
}