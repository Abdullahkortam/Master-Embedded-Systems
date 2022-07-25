/*
 * Ex6.c
 *
 *  Created on: ٢٥‏/٠٧‏/٢٠٢٢
 *      Author: mkm
 */

#include "stdio.h"

void main()
{
	printf("#########Console_output#########\n");
	float num1 ,num2 ,temp ;
	printf("Enter value of a:");
	fflush(stdout);
	fflush(stdin);
	scanf("%f",&num1);
	printf("Enter value of a:");
	fflush(stdout);
	fflush(stdin);
	scanf("%f",&num2);
	temp = num1 ;
	num1=num2;
	num2=temp;
	printf("After swapping, value of a =%0.2f\n",num1);
	printf("After swapping, value of b =%0.2f",num2);
	printf("\n################################");

}
