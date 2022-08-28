/*
 * fifo.h
 *
 *  Created on: ٢٨‏/٠٨‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#ifndef FIFO_H_
#define FIFO_H_

#include <stdint.h>
//User Configuration
#define element_type uint32_t
#define Length 5

//Defintion
typedef struct
{
	element_type length ;
	element_type count ;
	element_type* base ;
	element_type* tail ;
	element_type* Head ;
}FIFO_Buf_t;

typedef enum
{
	FIFO_no_error,
	FIFO_is_full,
	FIFO_is_empty,
	FIFO_Null
}buff_status;

//API
buff_status FIFO_enqueue (FIFO_Buf_t* fifo,element_type item);
buff_status FIFO_dequeue (FIFO_Buf_t* fifo,element_type* item);
buff_status FIFO_Is_Full (FIFO_Buf_t* fifo);
buff_status FIFO_Is_Empty (FIFO_Buf_t* fifo);
buff_status FIFO_init (FIFO_Buf_t* fifo,element_type* buf,element_type item);
void FIFO_print(FIFO_Buf_t* fifo);
#endif /* FIFO_H_ */
