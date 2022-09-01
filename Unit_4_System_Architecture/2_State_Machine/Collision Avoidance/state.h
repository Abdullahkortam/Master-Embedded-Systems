/*
 * state.h
 *
 *  Created on: ٠١‏/٠٩‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"

#define STATE_define(_STATE_FUN_)		void ST_##_STATE_FUN_()
#define STATE(_STATE_FUN_)				ST_##_STATE_FUN_

void US_set_distance(int d);
void DC_set_speed(int s);

#endif /* STATE_H_ */
