/*
 * main.c
 *
 *  Created on: ٢٥‏/٠٧‏/٢٠٢٢
 *      Author: abdullah Kortam
 */

#include "stdio.h"

void main()
{
	int num1 ,i, fac=1 ,num;
	printf("Enter a number:");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&num1);
	num=num1;
	if (num1 <0)
		printf("Error!!! Factorial of negative number doesn't exist.");
	else
	{
		for (i=0;i<num1;i++)
		{
			fac*=num;
			num--;
			if(num==1)
				break;
		}
		printf("Factorial = %d",fac);
}
}


