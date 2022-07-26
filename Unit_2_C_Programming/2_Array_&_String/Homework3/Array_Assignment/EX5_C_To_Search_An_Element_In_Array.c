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
	int num ,i , value ;

	printf("Enter no of elements: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		arr[i]=(i+1)*11;
		printf("%d\t",arr[i]);
	}

	printf("\nEnter the element to be searched: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&value);

	for(i=0;arr[i]!=value;i++);
	printf("Number Found at location :%d",i+1);

}
