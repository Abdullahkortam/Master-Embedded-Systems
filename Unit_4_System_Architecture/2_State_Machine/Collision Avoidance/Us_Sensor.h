/*
 * Us_Sensor.h
 *
 *  Created on: ٠١‏/٠٩‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#ifndef US_SENSOR_H_
#define US_SENSOR_H_

//States
enum
{
	us_busy
}US_state_id;


//Functions API
STATE_define(US_busy);

void US_init();

//Global pointer to function
extern void (*US_state)();

#endif /* US_SENSOR_H_ */
