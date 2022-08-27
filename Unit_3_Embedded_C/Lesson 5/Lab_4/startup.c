/*
 ******************************************************************************
 * @file           : startup.c
 * @author         : Abdullah Kortam
 ******************************************************************************
 */
#include <stdint.h>

extern uint32_t _STACK_TOP ;

extern uint32_t main() ;
void Reset_Handler();

void Default_Hundler()
{
    Reset_Handler();
}

void NMI_Handler ()          __attribute__((weak,alias("Default_Hundler")));
void H_Fault_Handler()       __attribute__((weak,alias("Default_Hundler")));
void Bus_Fault()             __attribute__((weak,alias("Default_Hundler")));
void Usage_Fault_Handler()   __attribute__((weak,alias("Default_Hundler")));

uint32_t vector[] __attribute__((section(".vextors")))={
    (uint32_t) &_STACK_TOP ,
    (uint32_t) &Reset_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&H_Fault_Handler,
    (uint32_t)&Bus_Fault,
    (uint32_t)&Usage_Fault_Handler
};

extern uint32_t _E_TEXT ;
extern uint32_t _S_DATA ;
extern uint32_t _E_DATA ;
extern uint32_t _S_BSS ;
extern uint32_t _E_BSS ;
uint32_t i ;
void Reset_Handler ()
{
    uint32_t DATA_SIZE = (uint8_t*)&_E_DATA - (uint8_t*)&_S_DATA ;
    uint8_t* P_src = (uint8_t*) &_E_TEXT ;
    uint8_t* P_des = (uint8_t*) &_S_DATA ;

    for(i=0;i<DATA_SIZE;i++)
    {
        *((uint8_t*)P_des++) = *((uint8_t*)P_src++) ;
    }

    uint32_t BSS_Size = (uint8_t*)&_E_BSS - (uint8_t*)&_S_BSS ;
	P_des = (uint8_t*)&_S_BSS ;

	for (i = 0; i < BSS_Size; ++i)
    {
			*((uint8_t*)P_des++) = (uint8_t)0 ;
    }
		main();
}
