/*
 * FirstMidTermExam_Code4.c
 *
 *  Created on: ٣١‏/٠٧‏/٢٠٢٢
 *      Author: abdullah kortam
 */
#include "stdio.h"

void main()
{
	int num1 ,i , key;
	printf("Enter a numbers:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num1);
	for(i=0;num1!=0;i++)
	{
		key=num1%10;
		num1/=10;
		printf("%d",key);
	}
}

