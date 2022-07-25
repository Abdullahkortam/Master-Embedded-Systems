/*
 * main.c
 *
 *  Created on: ٢٥‏/٠٧‏/٢٠٢٢
 *      Author: abdullah Kortam
 */

#include "stdio.h"

void main()
{
	char alpha ;
	printf("Enter a character:");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&alpha);
	if((alpha >='a' && alpha<='z') || ( alpha >='A' && alpha<='Z'))
		printf("%c is a character.",alpha);
	else
		printf("%c is not a character.",alpha);
}


