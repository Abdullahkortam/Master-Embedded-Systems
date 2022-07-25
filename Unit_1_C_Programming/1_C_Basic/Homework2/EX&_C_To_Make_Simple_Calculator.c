/*
 * main.c
 *
 *  Created on: ٢٥‏/٠٧‏/٢٠٢٢
 *      Author: abdullah Kortam
 */

#include "stdio.h"

void main()
{
	float num1 , num2 , cont;
	char operand ;
	printf("Enter operator either + or - or * or/:");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&operand);
	printf("Enter two number:\n");
	scanf("%f",&num1);
	scanf("%f",&num2);

	switch(operand)
	{
		case '+':
			cont = num1 + num2 ;
			break;
		case '-':
			 cont = num1 - num2 ;
			break ;
		case '*':
			cont = num1 * num2;
		case '/':
			cont = num1 / num2 ;
			break;
		default:
			printf("Error input!!!");
			break;
	}
	printf("%0.1f %c %0.1f = %f",num1,operand,num2,cont);
}


