/*
 * EX4_C_To_Print_The_Elements_Of_an_Array_in_Reverse_Order.c
 *
 *  Created on: ٠٧‏/٠٨‏/٢٠٢٢
 *      Author: mkm
 */

#include <stdio.h>

void main()
{
    int arr[15] ;
    int* p ;int i  , size;
    p= arr ;
    printf("Enter a number of elements (max 15) : ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
    	printf("Enter element :%d ",i+1);
        fflush(stdin);fflush(stdout);
        scanf("%d",p+i);
    }

    p= arr+ size -1 ;
    for(i=size;i>0;i--)
    {
    	printf("Element - %d : %d\n",i,*p);
    	p--;
    }
}
