/*
 * EX2_C_To_Swap_Two_Array_With_Different_Length.c
 *
 *  Created on: ٢٩‏/٠٧‏/٢٠٢٢
 *      Author: abdullah kortam
 */

#include <stdio.h>
#include <string.h>

void main()
{
	int arr1[10] , arr2[10] , temp[10] ,i;
	fflush(stdin);fflush(stdout);
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr1[i]);
	}

	fflush(stdin);fflush(stdout);
	for(i=0;i<5;i++)
	{
		scanf("%d",&arr2[i]);
	}

	printf("Before Swapping:\n");
	printf("First Array:\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t",arr1[i]);
	}
	printf("\nEnter a string: ");
	for(i=0;i<5;i++)
	{
		printf("%d\t",arr2[i]);
	}

	for(i=0;i<10;i++)
	{
		temp[i] = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp[i];
	}

	printf("\nAfter Swapping:\n");
	printf("First Array:\n");
	for(i=0;i<5;i++)
	{
		printf("%d\t",arr1[i]);
	}
	printf("\nSecond Array: ");
	for(i=0;i<10;i++)
	{
		printf("%d\t",arr2[i]);
	}
}