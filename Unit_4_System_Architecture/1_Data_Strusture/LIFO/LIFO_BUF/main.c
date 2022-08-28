/*
 * main.c
 *
 *  Created on: ٢٧‏/٠٨‏/٢٠٢٢
 *      Author: Abdullah kortam
 */


#include "lifo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

element_type buf[Length] ;

int main()
{
	LIFO_Buf_t uart_lifo ;
	element_type i , item =0 ;
	LIFO_init(&uart_lifo,buf,Length) ;

	for(i=0;i<Length;i++)
	{
		if(LIFO_push_item(&uart_lifo, i)==LIFO_no_error)
			printf("UART LIFO add : %d\n",i);
	}

	for(i=0;i<Length;i++)
		{
			if(LIFO_pop_item(&uart_lifo,&item)==LIFO_no_error)
				printf("UART LIFO pop : %d\n",item);
		}
	return 0 ;
}
