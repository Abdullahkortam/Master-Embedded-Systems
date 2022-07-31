/*
 * FirstMidTermExam_Code8.c
 *
 *  Created on: ٣١‏/٠٧‏/٢٠٢٢
 *      Author: abdullah kortam
 */

#include <stdio.h>

void Reverse(int x[] , int y);

void main()
{
	int arr[100] , size ,i;
	printf("Enter the size of array:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&size);
	for(i=0;i<size;i++)
	{
	    printf("Enter Element%d : ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",&arr[i]);
	}
	Reverse(arr,size);

}
void Reverse (int x[],int y)
{
	int b[100] , i;

	for(i=0;i<y;i++)
	{
		b[i]=x[y-i-1];
	}
	printf("Result of an Reverse Array:\n");
	for(i=0;i<y;i++)
	{
		printf("%d\t",b[i]);
	}
}
