/*
 * pp.c
 *
 *  Created on: ٢٦‏/٠٧‏/٢٠٢٢
 *      Author: mkm
 */

#include "stdio.h"

void main()
{
	char string [100] , value;
	int freq=0 ,i;

	printf("Enret a string:\n");
	fflush(stdin);fflush(stdout);
	gets(string);

	printf("Enter a character to find frequency:\n");
	fflush(stdin);fflush(stdout);
	scanf("%c",&value);

	for(i=0;string[i]!='\0';i++)
	{
		if(string[i] == value)
			freq++;
	}

	printf("Frequency of %c :%d",value,freq);
}
