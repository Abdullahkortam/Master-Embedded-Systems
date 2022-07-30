/*
 * EX6_C_To_Know_The_4th_Least_Bit_In_Binary.c
 *
 *  Created on: ٣٠‏/٠٧‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#include <Stdio.h>

void main()
{
    int num ,i , flag ;
    printf("Enter an integer number in decimal system:\n");
    fflush(stdin);fflush(stdout);
    scanf("%d",&num);
    printf("%d in binary number system is : ",num);
    for(i=31; i>=0 ;i--)
    {
        flag=num>>i ;
        if(flag&1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
    flag=num>>3 ;
    if(flag&1)
        printf("4th least significant bit is 1");
    else
        printf("4th least significant bit is 0");
}

