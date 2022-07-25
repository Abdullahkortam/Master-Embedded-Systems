/*
 * main.c
 *
 *  Created on: ٢٥‏/٠٧‏/٢٠٢٢
 *      Author: abdullah Kortam
 */

#include "stdio.h"

void main()
{
	int num1  ,i ,sum=0;
	printf("Enter a number:");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&num1);

	for(i=1;i<=num1;i++)
	{
		sum+=i;
	}
	printf("sum =%d.",sum);

}


