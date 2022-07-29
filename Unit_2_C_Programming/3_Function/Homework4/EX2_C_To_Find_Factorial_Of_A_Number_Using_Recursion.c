/*
 * main.c
 *
 *  Created on: ٢٩‏/٠٧‏/٢٠٢٢
 *      Author: mkm
 */


#include "stdio.h"

int factorial (int x);

void main()
{
	int num1 , fact  ,i;
	printf("Enter a positive number:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num1);

	fact = factorial(num1);
	printf("Factorial of %d = %d",num1,fact);
}
int factorial (int x)
{
    if (x==0)
        return 1;
    if(x!=1)
		return x * factorial(x-1) ;
}
