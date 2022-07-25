/*
 * Ex2.c
 *
 *  Created on: ٢٥‏/٠٧‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#include "stdio.h"
void main()
{
	float num1 , num2 , num3 ;
	printf("Enter three numbers:");
	fflush(stdout);
	fflush(stdin);
	scanf("%f",&num1);
	scanf("%f",&num2);
	scanf("%f",&num3);

	if(num1 > num2)
	{
		if (num1> num3)
			printf("Largest Number=%f",num1);
		else
			printf("Largest Number=%f",num3);
	}
	else
	{
		if(num2 > num3)
			printf("Largest Number=%f",num2);
		else
			printf("Largest Number=%f",num3);
	}

}



