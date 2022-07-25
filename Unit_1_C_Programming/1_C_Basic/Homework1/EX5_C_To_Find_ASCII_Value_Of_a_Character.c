/*
 * main2.c
 *
 *  Created on: ٢٥‏/٠٧‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#include "stdio.h"

void main()
{
	printf("#########Console_output#########\n");
	char ch ;
	printf("Enter a character:");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&ch);
	printf("ASCII value of %c =%d",ch,ch);
	printf("\n################################");
}


