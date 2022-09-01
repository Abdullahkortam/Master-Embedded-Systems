/*
 * Dc_Motor.h
 *
 *  Created on: ٠١‏/٠٩‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "state.h"

//States
enum
{
	dc_idle,
	dc_busy
}DC_state_id;


//Functions APIs
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();


//Global pointer to function
extern void (*DC_state)();
#endif /* DC_MOTOR_H_ */
