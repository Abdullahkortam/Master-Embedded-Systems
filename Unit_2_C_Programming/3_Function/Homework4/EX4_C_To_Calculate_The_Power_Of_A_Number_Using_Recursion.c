/*
 * EX4_C_To_Calculate_The_Power_Of_A_Number_Using_Recursion.c
 *
 *  Created on: ٢٩‏/٠٧‏/٢٠٢٢
 *      Author: abdullah kortam
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int power_N0 (int x , int y);

void main()
{
	int base , power ;
	printf("Enter base number:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&base);
	printf("Enter power (positive number):\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&power);
	int result = power_N0(base,power);
	printf("%d ^ %d = %d",base,power,result);
}

int power_N0 (int x , int y)
{
   if(y==0)
    return 1;
   else
    return pow(x,y);
}
