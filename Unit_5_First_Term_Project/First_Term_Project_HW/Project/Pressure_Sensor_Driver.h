/************************************************************************************************************
 *  Pressure_Sensor_Driver.h
 *  Second_Term_project HW
 *  Created on: ١٢‏/٠٩‏/٢٠٢٢
 *  Author: Abdullah Kortam
 ************************************************************************************************************/

#ifndef PRESSURE_SENSOR_DRIVER_H_
#define PRESSURE_SENSOR_DRIVER_H_
#include "state.h"

/* Define states */
enum
{
	PRESSURE_SENSOR_DRIVER_reading,
	PRESSURE_SENSOR_DRIVER_waiting
} PRESSURE_SENSOR_DRIVER_state_id;

/* Declare init function */
void Pressure_Sensor_Driver_init (void);

/* Declare states functions */
STATE_define(PRESSURE_SENSOR_DRIVER_reading);
STATE_define(PRESSURE_SENSOR_DRIVER_waiting);

/* State pointer (pointer to function) */
extern void (*PRESSURE_SENSOR_DRIVER_state)();

#endif /* PRESSURE_SENSOR_DRIVER_H_ */
