/************************************************************************************************************
 *  Alarm_Monitor.h
 *  Second_Term_project HW
 *  Created on: ١٢‏/٠٩‏/٢٠٢٢
 *  Author: Abdullah Kortam
 ************************************************************************************************************/

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_
#include "state.h"

/* Define states */
enum
{
	ALARM_MONITOR_alarm_off,
	ALARM_MONITOR_alarm_on,
	ALARM_MONITOR_waiting
} ALARM_MONITOR_state_id;

/* Declare states functions */
STATE_define(ALARM_MONITOR_alarm_off);
STATE_define(ALARM_MONITOR_alarm_on);
STATE_define(ALARM_MONITOR_waiting);

/* State pointer (pointer to function) */
extern void (*ALARM_MONITOR_state)();

#endif /* ALARM_MONITOR_H_ */
