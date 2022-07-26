/*
 * EX2_C_To_Calculate_Average_Using_array.c
 *
 *  Created on: ٢٦‏/٠٧‏/٢٠٢٢
 *      Author: mkm
 */

#include "stdio.h"

void main()
{
	float arr[100] , average=0;
	int num1 ,i ;
	printf("Enter the number of data: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num1);

	for(i=0;i<num1;i++)
	{
		printf("Enter number %d: ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&arr[i]);
		average+=arr[i];
	}
	average/=num1;
	printf("Average = %0.2f",average);

}

