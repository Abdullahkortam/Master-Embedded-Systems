/*
 * EX5_C_To_Clear_Bit_In_A_Given_Number.c
 *
 *  Created on: ٣٠‏/٠٧‏/٢٠٢٢
 *      Author: mkm
 */

#include <Stdio.h>

int reset(int x , int y);

void main()
{
    int num , position ;
	printf("Enter a number:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
    printf("Enter a position:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&position);
    num =reset(num,position);
	printf("%d",num);
}
int reset(int x,int y)
{
    x &= ~(1<<y);
    return x ;
}
