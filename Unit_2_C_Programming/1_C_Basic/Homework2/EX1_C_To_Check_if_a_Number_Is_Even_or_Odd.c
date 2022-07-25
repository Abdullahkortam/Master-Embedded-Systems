/*
 * main.c
 *
 *  Created on: ٢٣‏/٠٧‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */
#include "stdio.h"
void main()
{
	int num1 ;
	printf("Enter an integer you want to check:\n");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&num1);
	if (num1 %2 == 1)
	{
		printf("%d is odd.",num1);
	}
	else
	{
		printf("%d is even.",num1);
	}
}

