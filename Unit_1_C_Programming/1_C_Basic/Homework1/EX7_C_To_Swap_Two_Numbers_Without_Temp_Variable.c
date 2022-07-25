/*
 * Ex7.c
 *
 *  Created on: ٢٥‏/٠٧‏/٢٠٢٢
 *      Author: mkm
 */

#include "stdio.h"

void main()
{
	printf("#########Console_output#########\n");
	int num1 ,num2 ;
	printf("Enter value of a:");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&num1);
	printf("Enter value of a:");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&num2);
	num1+=num2 ;
	num2=num1-num2;
	num1=num1-num2;
	printf("After swapping, value of a =%d\n",num1);
	printf("After swapping, value of b =%d",num2);
	printf("\n################################");
}

