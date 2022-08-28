/*
 * lifo.c
 *
 *  Created on: ٢٧‏/٠٨‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#include "lifo.h"
#include <stdio.h>
#include <stdlib.h>

Buff_status LIFO_IS_Empty(LIFO_Buf_t * lifo_buf)
{
	//check if LIFO is full
	if(lifo_buf->Head == lifo_buf->Base)
		return LIFO_is_empty;
	else
		return LIFO_not_empty ;
}

Buff_status LIFO_IS_Full(LIFO_Buf_t * lifo_buf)
{
	//check if LIFO is full
	if(lifo_buf->count == lifo_buf->length)
		return LIFO_is_full ;
	else
		return LIFO_not_full ;
}

Buff_status LIFO_push_item(LIFO_Buf_t * lifo_buf,element_type item)
{
	//check if LIFO is valid
	if(!lifo_buf->Base || !lifo_buf->Head)
		return LIFO_Null ;

	//check if LIFO is full
	if(LIFO_IS_Full(lifo_buf)==LIFO_is_full)
		return LIFO_not_full ;

	//add item to LIFO
	*(lifo_buf->Head) = item ;
	lifo_buf->Head ++ ;
	lifo_buf->count ++ ;

	return LIFO_no_error ;
}

Buff_status LIFO_pop_item(LIFO_Buf_t * lifo_buf,element_type* item)
{
	//check if LIFO is valid
	if(!lifo_buf->Base || !lifo_buf->Head)
		return LIFO_Null ;

	//check if LIFO is full
	if(LIFO_IS_Empty(lifo_buf)==LIFO_is_empty)
		return LIFO_Null ;

	//pop item
	lifo_buf->Head -- ;
	*item = *(lifo_buf->Head) ;
	lifo_buf->count -- ;

	return LIFO_no_error ;
}
Buff_status LIFO_init(LIFO_Buf_t * lifo_buf, element_type* buf , element_type length)
{
	if(lifo_buf == NULL)
		return LIFO_Null ;

	lifo_buf->Base = buf ;
	lifo_buf->Head = buf ;
	lifo_buf->length = length ;
	lifo_buf->count =0 ;

	return LIFO_no_error ;
}
