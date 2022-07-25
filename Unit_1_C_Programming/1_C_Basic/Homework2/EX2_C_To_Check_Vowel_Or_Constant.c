/*
 * Ex2.c
 *
 *  Created on: ٢٥‏/٠٧‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#include "stdio.h"
void main()
{
	char ch ;
	printf("Enter an alphpet:\n");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&ch);
	if(ch == 'o' || ch =='i' ||ch =='u' ||ch == 'e'|| ch =='a' || ch =='A' ||ch == 'O' ||ch == 'E' || ch =='U' || ch =='I')
	{
		printf("%c is a vowel.",ch);
	}
	else
	{
		printf("%c is a constant.",ch);
	}
}



