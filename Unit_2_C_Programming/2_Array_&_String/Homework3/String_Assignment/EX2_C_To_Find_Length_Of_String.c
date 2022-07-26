/*
 * lll.c
 *
 *  Created on: ٢٦‏/٠٧‏/٢٠٢٢
 *      Author: mkm
 */

#include "stdio.h"

void main()
{
	char string [100];
	int length =0 ,i ;

	printf("Enter a string:\n");
	fflush(stdin);fflush(stdout);
	scanf("%s",string);

	for(i=0;string[i]!='\0';i++)
	{
		length ++;
	}

	printf("Length of string: %d",length);
}
