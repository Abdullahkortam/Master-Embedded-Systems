/************************************************************************************************************
 *  Alarm_Actuator_Driver.h
 *  Second_Term_project HW
 *  Created on: ١٢‏/٠٩‏/٢٠٢٢
 *  Author: Abdullah Kortam
 ************************************************************************************************************/
#ifndef ALARM_ACTUATOR_DRIVER_H_
#define ALARM_ACTUATOR_DRIVER_H_
#include "state.h"

/* Define states */
enum
{
	ALARM_ACTUATOR_DRIVER_alarm_off,
	ALARM_ACTUATOR_DRIVER_alarm_on,
	ALARM_ACTUATOR_DRIVER_waiting
} ALARM_ACTUATOR_DRIVER_state_id;

/* Declare init function */
void Alarm_Actuator_Driver_init (void);

/* Declare states functions */
STATE_define(ALARM_ACTUATOR_DRIVER_alarm_off);
STATE_define(ALARM_ACTUATOR_DRIVER_alarm_on);
STATE_define(ALARM_ACTUATOR_DRIVER_waiting);

/* State pointer (pointer to function) */
extern void (*ALARM_ACTUATOR_DRIVER_state)();

#endif /* ALARM_ACTUATOR_DRIVER_H_ */
