/************************************************************************************************************
 *  Main_Algorithm.h
 *  Second_Term_project HW
 *  Created on: ١٢‏/٠٩‏/٢٠٢٢
 *  Author: Abdullah Kortam
 ************************************************************************************************************/

#ifndef MAIN_ALGORITHM_H_
#define MAIN_ALGORITHM_H_
#include "state.h"

/* Define states */
enum
{
	MAIN_ALGORITHM_high_pressure_detect
} MAIN_ALGORITHM_state_id;

/* Declare states functions */
STATE_define(MAIN_ALGORITHM_high_pressure_detect);

/* State pointer (pointer to function) */
extern void (*MAIN_ALGORITHM_state)();

#endif /* MAIN_ALGORITHM_H_ */
