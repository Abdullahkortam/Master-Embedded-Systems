/*
 * FirstMidTermExam_Code3.c
 *
 *  Created on: ٣١‏/٠٧‏/٢٠٢٢
 *      Author: abdullah kortam
 */
#include "stdio.h"

void prime_No (int x);

void main()
{
	int num1 , num2  ,i;
	printf("Enter two numbers (interval):\n");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&num1,&num2);
	printf("prime number between:%d and %d: ",num1,num2);
	for(i=num1;i<=num2;i++)
	{
		prime_No(i);
	}

}

void prime_No (int x )
{
	int i  ,flag=0;
    for(i=2;i<=x/2;i++)
    {
        if(x%i ==0)
        {
            flag =1 ;
            break;
        }
    }
    if(flag==0)
        printf("%d\t",x);

}
