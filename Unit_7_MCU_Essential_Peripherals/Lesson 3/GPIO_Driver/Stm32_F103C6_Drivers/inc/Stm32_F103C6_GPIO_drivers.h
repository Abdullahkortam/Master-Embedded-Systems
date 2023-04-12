/*
 * Stm32_F103C6_GPIO_drivers.h
 *
 *  Created on: Nov 30, 2022
 *      Author: Abdullah Kortam
 */

#ifndef INC_STM32_F103C6_GPIO_DRIVERS_H_
#define INC_STM32_F103C6_GPIO_DRIVERS_H_

#include "Stm32F103Cx6.h"

typedef struct
{
	uint16_t GPIO_PinNumber 	;

	uint8_t GPIO_Mode			;

	uint8_t GPIO_Output_Speed 	;
}GPIO_PinConfig_t;

//@ref GPIO_Pin_define
#define GPIO_Pin_0 	    ((uint16_t)0x0001)
#define GPIO_Pin_1  	((uint16_t)0x0002)
#define GPIO_Pin_2  	((uint16_t)0x0004)
#define GPIO_Pin_3  	((uint16_t)0x0008)
#define GPIO_Pin_4  	((uint16_t)0x0010)
#define GPIO_Pin_5  	((uint16_t)0x0020)
#define GPIO_Pin_6  	((uint16_t)0x0040)
#define GPIO_Pin_7  	((uint16_t)0x0080)
#define GPIO_Pin_8  	((uint16_t)0x0100)
#define GPIO_Pin_9  	((uint16_t)0x0200)
#define GPIO_Pin_10  	((uint16_t)0x0400)
#define GPIO_Pin_11 	((uint16_t)0x0800)
#define GPIO_Pin_12 	((uint16_t)0x1000)
#define GPIO_Pin_13 	((uint16_t)0x2000)
#define GPIO_Pin_14 	((uint16_t)0x4000)
#define GPIO_Pin_15 	((uint16_t)0x8000)
#define GPIO_Pin_ALL 	((uint16_t)0xFFFF)

#define GPIO_Pin_Mask  		0x0000FFFFu

//@ref GPIO_Mode_define
//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up
//3: Input with pull-down
//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain
//8: Alternate function Input

#define GPIO_Mode_Analog			0x00000000u
#define GPIO_Mode_Input_FLO			0x00000001u
#define GPIO_Mode_Input_PU			0x00000002u
#define GPIO_Mode_Input_PD			0x00000003u
#define GPIO_Mode_Output_PU			0x00000004u
#define GPIO_Mode_Output_PD			0x00000005u
#define GPIO_Mode_Output_AF_PP		0x00000006u
#define GPIO_Mode_Output_AF_OD		0x00000007u
#define GPIO_Mode_AF_Input			0x00000008u

//@ref GPIO_Speed_Define
//01: Output mode, max speed 10 MHz.
//2: Output mode, max speed 2 MHz.
//3: Output mode, max speed 50 MHz
#define GPIO_Speed_10M 				0x00000001u
#define GPIO_Speed_2M 				0x00000002u
#define GPIO_Speed_50M 				0x00000003u

//@ref GPIO_PIN_state
#define GPIO_PIN_SET  					1
#define GPIO_PIN_RESET  				0

//@ref GPIO_RETURN_LOCK
#define GPIO_RETURN_LOCK_Enabled 		1
#define GPIO_RETURN_LOCK_ERROR	 		0

/*
 * =========================================================================
 * 							GPIO_APIs_Supported_By_MCAL
 * ==========================================================================
 */

void MCAL_GPIO_Init  	(GPIO_TypeDef * GPIOx ,GPIO_PinConfig_t* PinConfig);
void MCAL_GPIO_DeINIT	(GPIO_TypeDef * GPIOx);
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);
uint16_t  MCAL_GPIO_ReadPort (GPIO_TypeDef * GPIOx);
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint8_t Value);
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t Value);
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);

#endif /* INC_STM32_F103C6_GPIO_DRIVERS_H_ */
