/*
 * main.c
 *
 *  Created on: ٢٥‏/٠٧‏/٢٠٢٢
 *      Author: abdullah Kortam
 */

#include "stdio.h"

void main()
{
	printf("#########Console_output#########\n");
	int num1 ,num2;
	printf("Enter two number:");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&num1);
	scanf("%d",&num2);
	printf("sum: %d",num1+num2);
	printf("\n################################");
}


