/*
 ******************************************************************************
 * @file           : startup.c
 * @author         : Abdullah Kortam
 ******************************************************************************
 */
#include <stdint.h>

extern uint32_t main() ;
void Reset_Handler();

void Default_Hundler()
{
    Reset_Handler();
}

void NMI_Handler ()          __attribute__((weak,alias("Default_Hundler")));
void H_Fault_Handler()       __attribute__((weak,alias("Default_Hundler")));

static unsigned long Stack_top [256];

void (*const g_p_vector[])()__attribute__((section(".vextors")))=
{
    (void (*) ()) ((unsigned long)Stack_top + sizeof(Stack_top)),
    &Reset_Handler,
    &NMI_Handler,
    &H_Fault_Handler
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
    uint8_t *P_src = (uint8_t*) &_E_TEXT ;
    uint8_t *P_des = (uint8_t*) &_S_DATA ;

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