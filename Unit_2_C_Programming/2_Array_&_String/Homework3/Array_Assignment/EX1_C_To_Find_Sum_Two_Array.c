/*
 * main.c
 *
 *  Created on: ٢٥‏/٠٧‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#include "stdio.h"

void main()
{
	float a[2][2] , b[2][2];
	int i ,j ;
	printf("Enter the elements of the 1st matrix:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Enter a%d%d : ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&a[i][j]);
		}
	}
	printf("Enter the elements of the 2nd matrix:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Enter b%d%d : ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&b[i][j]);
			a[i][j]+=b[i][j];
		}
	}
	printf("Sum Of Matrix:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%0.1f\t",a[i][j]);
			if(j==1)
				printf("\n");

		}
	}

}
