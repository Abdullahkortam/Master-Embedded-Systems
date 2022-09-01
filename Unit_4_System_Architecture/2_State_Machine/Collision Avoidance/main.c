/*
 * main.c
 *
 *  Created on: ٠١‏/٠٩‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#include "Collision_Avoidanc.h"
#include "Dc_Motor.h"
#include "Us_Sensor.h"
void setup ()
{
	//initialize all drivers
	//initialize IRQ
	//initialize HAL US_DRIVER DC_DRIVER
	//initialize all blocks
	US_init();
	DC_init();
	//set states pointers for each block
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);

}


int main()
{
	int d;
	setup();
	while(1)
	{
		US_state();
		CA_state();
		DC_state();
		for(d=0; d<=1000; d++);
	}

	return 0;
}
