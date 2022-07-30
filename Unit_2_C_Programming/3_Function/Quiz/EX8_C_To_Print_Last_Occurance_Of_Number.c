/*
 * EX8_C_To_Print_Last_Occurance_Of_Number.c
 *
 *  Created on: ٣٠‏/٠٧‏/٢٠٢٢
 *      Author: abdullah kortam
 */

#include <stdio.h>

int last_Occur (int x[], int y);

void main()
{
	int arr[100] , size ,i ;
	printf("Enter the size of the array:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&size);

	for (i=0;i<size;i++)
	{
		printf("Enter Element%d : ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",&arr[i]);
	}

	int flag = last_Occur(arr,size);
	printf("Last occurance : %d",flag);
}
int last_Occur (int x[], int y)
{
	int key ,i ;
	printf("Enter the number you want to get its last occurance:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&key);

	for(i=y-1;i>=0;i--)
	{
		if(key==x[i])
			return i+1;
	}
	return -1 ;
}
