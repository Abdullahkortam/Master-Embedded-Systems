#include <stdio.h>
#include "uart.h"

unsigned char string[100]="Learn-in-depth: <Abdullah>" ;

void main (void)
{
    uart_send_string (string) ;
}
