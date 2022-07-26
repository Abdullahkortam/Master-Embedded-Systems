/*
 * pp.c
 *
 *  Created on: ٢٦‏/٠٧‏/٢٠٢٢
 *      Author: mkm
 */

#include "stdio.h"
void main()
{
	int arr[100];
	int num ,i  , index =0,value=0;

	printf("Enter no of elements: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		arr[i]=i+1;
		printf("%d\t",arr[i]);
	}
	printf("\nEnter the element to be inserted :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&value);

	printf("Enter the location:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&index);

	arr[index-1] = value;

	for(i=0;i<num;i++)
	{
		printf("%d\t",arr[i]);
	}
}
