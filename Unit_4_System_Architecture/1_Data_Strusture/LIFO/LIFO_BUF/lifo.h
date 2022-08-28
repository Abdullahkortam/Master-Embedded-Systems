/*
 * lifo.h
 *
 *  Created on: ٢٧‏/٠٨‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#ifndef LIFO_H_
#define LIFO_H_
#include <stdint.h>
//User Configuration
#define element_type uint32_t
#define Length 5

typedef struct Lifo_buf
{
	element_type length ;
	element_type count ;
	element_type* Head ;
	element_type* Base ;
}LIFO_Buf_t;
//Defintion
typedef enum
{
	LIFO_no_error,
	LIFO_is_full,
	LIFO_not_full,
	LIFO_is_empty,
	LIFO_not_empty,
	LIFO_Null
}Buff_status;

//API
Buff_status LIFO_IS_Full(LIFO_Buf_t* lifo_buf);
Buff_status LIFO_IS_Empty(LIFO_Buf_t* lifo_buf);
Buff_status LIFO_push_item(LIFO_Buf_t* lifo_buf,element_type item);
Buff_status LIFO_pop_item(LIFO_Buf_t* lifo_buf,element_type* item);
Buff_status LIFO_init(LIFO_Buf_t* lifo_buf, element_type* buf , element_type length);

#endif /* LIFO_H_ */
