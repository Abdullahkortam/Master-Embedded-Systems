/*
 * EX1_C_To_Takes_String_From_The_User_And_Check _If_It_The_Same_Username_Or_Not.c
 *
 *  Created on: ٢٩‏/٠٧‏/٢٠٢٢
 *      Author: abdullah kortam
 */

#include <stdio.h>
#include <string.h>

void main()
{
	char arr1[100] , arr2[100];
	int flag ;
	printf("Enter a string:\n");
	fflush(stdin);fflush(stdout);
	gets(arr1);

	printf("Enter Your name:\n");
	fflush(stdin);fflush(stdout);
	gets(arr2);

	flag=stricmp(arr2,arr1);
	if(flag==0)
		printf("Identical.");
	else
		printf("Different.");
}


