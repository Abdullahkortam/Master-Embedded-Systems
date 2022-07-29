/*
 * EX3_C_To_Reverse_A_Sentence_Using_Recursion.c
 *
 *  Created on: ٢٩‏/٠٧‏/٢٠٢٢
 *      Author: abdullah kortam
 */

#include <stdio.h>
#include<string.h>

int reverse (int y);
char string[100];

void main()
{
	int length ;
	printf("Enter a sentence:\n");
	fflush(stdin);fflush(stdout);
	gets(string);
    length =strlen(string);
	reverse(length-1);
}

int reverse (int y)
{
    printf("%c",string[y]);
    if(y!=-1)
        return 1*reverse(y-1);
    else
    	return 0;
}
