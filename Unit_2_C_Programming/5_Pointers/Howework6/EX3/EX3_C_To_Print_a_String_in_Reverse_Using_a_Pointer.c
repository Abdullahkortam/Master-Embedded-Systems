/*
 * EX3_C_To_Print_a_String_in_Reverse_Using_a_Pointer.c
 *
 *  Created on: ٠٧‏/٠٨‏/٢٠٢٢
 *      Author: abdullah kortam
 */


#include <stdio.h>
#include <string.h>

void main()
{
    char ch [100] ;
    printf("Enter a string: ");
    fflush(stdin);fflush(stdout);
    gets(ch);
    char* p ;
    int i ;
    int len = strlen(ch);
    p= ch + len-1;
    printf("Reverse of the string is : ");
    fflush(stdin);fflush(stdout);
    for(i=len;i>=0;i--)
    {
        printf("%c",*p);
        p--;
    }
}

