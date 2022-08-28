/*
 * main.c
 *
 *  Created on: ٢٨‏/٠٨‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#include "fifo.h"
#include <stdio.h>
#include <stdlib.h>

element_type buf[Length] ;
int main()
{
	FIFO_Buf_t uart_fifo ;
	element_type i  , item;
	if(FIFO_init(&uart_fifo,buf,Length)==FIFO_no_error)
        printf("FIFO INIT --DONE\n");
    for(i=0;i<7;i++)
    {
        printf("FIFO Enqueue (%x)\n",i);
        if(FIFO_enqueue(&uart_fifo,i)==FIFO_no_error)
            printf("FIFO Enqueue --Done\n");
        else
            printf("FIFO Enqueue --Failed\n");
    }

    FIFO_print(&uart_fifo);
    printf("---------------------------------------------------------------------------\n");
    FIFO_dequeue(&uart_fifo,&item);
    printf("FIFO Dequeue: %x\n",item);
    FIFO_dequeue(&uart_fifo,&item);
    printf("FIFO Dequeue: %x\n",item);

    for(i=0;i<2;i++)
    {
    	printf("FIFO Enqueue (%X)\n",i);
    	if(FIFO_enqueue(&uart_fifo,i)==FIFO_no_error)
    		printf("FIFO Enqueue --Done\n");
    	else
    		printf("FIFO Enqueue --Failed\n");
    }
    FIFO_print(&uart_fifo);
    printf("---------------------------------------------------------------------------\n");
	return 0 ;
}

