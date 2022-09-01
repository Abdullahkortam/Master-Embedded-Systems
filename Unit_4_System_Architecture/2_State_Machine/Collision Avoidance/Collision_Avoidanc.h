/*
 * Collision_Avoidanc.h
 *
 *  Created on: ٠١‏/٠٩‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#ifndef COLLISION_AVOIDANC_H_
#define COLLISION_AVOIDANC_H_

#include "state.h"

//States
enum
{
	CA_waiting,
	CA_driving
}CA_state_id;


//Functions APIs
STATE_define(CA_waiting);
STATE_define(CA_driving);


//Global pointer to function
extern void (*CA_state)();

#endif /* COLLISION_AVOIDANC_H_ */
