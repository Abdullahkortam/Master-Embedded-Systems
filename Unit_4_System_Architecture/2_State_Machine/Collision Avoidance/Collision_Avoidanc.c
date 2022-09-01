/*
 * Collision_Avoidanc.c
 *
 *  Created on: ٠١‏/٠٩‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#include "Collision_Avoidanc.h"
unsigned int speed = 0;
unsigned int distance = 0;
unsigned int threshold = 50;


void (*CA_state)();



STATE_define(CA_waiting)
{

	CA_state_id = CA_waiting;
	printf("CA Waiting state : distance = %d speed = %d\n", distance, speed);

	speed = 0;
	DC_set_speed(speed);

}


STATE_define(CA_driving)
{

	CA_state_id = CA_driving;
	printf("CA Driving state : distance = %d speed = %d\n", distance, speed);

	speed = 30;
	DC_set_speed(speed);
}


void US_set_distance(int d)
{
	distance = d;

	(distance <= threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));

}
