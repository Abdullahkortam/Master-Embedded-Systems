/*
 * main.c
 *
 *  Created on: ٢٥‏/٠٧‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#include "stdio.h"
void main()
{
	float num1 ;
	printf("Enter a numbers:");
	fflush(stdout);
	fflush(stdin);
	scanf("%f",&num1);

	if(num1 > 0)
		printf("%0.2f is Positive.",num1);
	else if(num1 < 0)
		printf("%0.2f is negative.",num1);
	else
		printf("You entered Zero.");
}
