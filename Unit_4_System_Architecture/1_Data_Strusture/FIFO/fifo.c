
/*
 * fifo.c
 *
 *  Created on: ٢٨‏/٠٨‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#include "fifo.h"
#include <stdio.h>
#include <stdlib.h>
//API
buff_status FIFO_enqueue (FIFO_Buf_t* fifo,element_type item)
{
	//check if FIFO is valid
	if(!fifo->base || !fifo->Head || !fifo->tail)
		return FIFO_Null ;

	//check if FIFO is full?
	if(FIFO_Is_Full(fifo)==FIFO_no_error)
	{


		*(fifo->Head) = item ;
		fifo->count ++;

		if((fifo->Head)== ((fifo->base))+(fifo->length *sizeof(element_type)))
			fifo->Head = fifo->base ;
		else
			fifo->Head ++ ;
		return FIFO_no_error ;
	}
	else
	{
		printf("FIFO Enqueue Failed.\n");
		return FIFO_is_full ;
	}
}

buff_status FIFO_dequeue (FIFO_Buf_t* fifo,element_type* item)
{
	//check if FIFO is valid
	if(!fifo->base || !fifo->Head || !fifo->tail)
		return FIFO_Null ;

	//check if FIFO is Empty?
	if(FIFO_Is_Empty(fifo) ==FIFO_is_empty)
	{
		printf("FIFO is Empty!!\n");
		return FIFO_is_empty ;
	}

	*item =*(fifo->tail);
	fifo->count-- ;

	if((fifo->tail)== ((fifo->base)+(fifo->length)*sizeof(element_type)))
		fifo->tail = fifo->base ;
	else
		fifo->tail++ ;

	return FIFO_no_error ;
}

buff_status FIFO_Is_Full (FIFO_Buf_t* fifo)
{
	//check if FIFO is valid
	if(!fifo->base || !fifo->Head || !fifo->tail)
		return FIFO_Null ;

	//check if FIFO is full?
	if(fifo->count == fifo->length)
		return FIFO_is_full ;
	else
		return FIFO_no_error;
}

buff_status FIFO_Is_Empty (FIFO_Buf_t* fifo)
{
	//check if FIFO is valid
	if(!fifo->base || !fifo->Head || !fifo->tail)
		return FIFO_Null ;

	//check if FIFO is Empty?
	if(fifo->count == 0)
		return FIFO_is_empty ;

	return FIFO_no_error ;
}
buff_status FIFO_init (FIFO_Buf_t* fifo,element_type* buf,element_type length)
{
	if(fifo->base == NULL)
		return FIFO_Null;

	fifo->Head = buf ;
	fifo->base = buf ;
	fifo->tail = buf ;
	fifo->length = length ;
	fifo->count = 0 ;

	return FIFO_no_error ;
}

void FIFO_print(FIFO_Buf_t* fifo)
{
	element_type* temp ;
	temp = fifo->tail ;
	uint8_t i ;
	if(fifo->count == 0)
		printf("FIFO is Empty!!");


	for(i=0;i<fifo->count;i++)
	{
		printf("%X\n",*temp);
		temp++;
	}
}

