/*
 * lll.c
 *
 *  Created on: ٢٦‏/٠٧‏/٢٠٢٢
 *      Author: mkm
 */

#include "stdio.h"

void main()
{
	char string [100] , reverse[100];
	int length =0 ;
	int i ;

	printf("Enter a string:\n");
	fflush(stdin);fflush(stdout);
	scanf("%s",string);

	length =strlen(string);

	for(i=0;i<length;i++)
	{
		reverse[length-i-1] = string[i];
	}
	reverse[i] = '\0';
	printf("Reverse string is : %s",reverse);
}
