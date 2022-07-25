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
	float num1 ,num2;
	printf("Enter two number:");
	fflush(stdout);
	fflush(stdin);
	scanf("%f",&num1);
	scanf("%f",&num2);
	printf("product: %f",num1*num2);
	printf("\n################################");
}


