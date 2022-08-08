/*
 * EX2_C_To_Print_All_Alphabets_Using_a_Pointer.c
 *
 *  Created on: ٠٧‏/٠٨‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#include <stdio.h>

void main()
{
    char ch [27] ;
    char* p ;
    p= ch ;
    int i ;
    for(i=0;i<26;i++)
    {
        *p = 'A' + i ;
        p ++ ;
    }
    p= ch ;
    printf("Alphabet is :\n");
    for(i=0;i<26;i++)
    {
        printf("%c ",*p);
        p++;
    }
}



