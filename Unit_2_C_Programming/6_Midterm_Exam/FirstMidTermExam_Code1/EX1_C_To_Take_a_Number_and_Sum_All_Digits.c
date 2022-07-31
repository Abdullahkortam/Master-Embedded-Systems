/*
 * FirstMidTermExam_Code1.c
 *
 *  Created on: ٣١‏/٠٧‏/٢٠٢٢
 *      Author: abdullah kortam
 */

#include <stdio.h>
#include <math.h>

void main()
{
	int num , i, sum=0 ;
	printf("Enter a number:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	for(i=0;num!=0;i++)
    {
        sum+=num%10;
        num/=10 ;
    }
    printf("Sum : %d",sum);
}

