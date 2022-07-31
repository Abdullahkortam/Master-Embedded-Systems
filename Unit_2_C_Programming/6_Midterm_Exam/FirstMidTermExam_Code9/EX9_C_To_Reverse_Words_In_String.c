/*
 * FirstMidTermExam_Code9.c
 *
 *  Created on: ٣١‏/٠٧‏/٢٠٢٢
 *      Author: abdullah kortam
 */

#include <stdio.h>

void main()
{
	char string[100], reverse[100];
	int i , length , len_R;

	printf("Enter a string:\n");
	fflush(stdin);fflush(stdout);
	gets(string);

	length =strlen(string);
	for(i=0;string[i]!=' ';i++);

	strcpy(reverse,string+i+1);
	len_R=strlen(reverse);
    reverse[len_R]=' ';

	for(i=0;string[i]!='\0';i++)
        reverse[len_R+i+1] = string[i];

    reverse[i]='\0';
    printf("Reverse name: %s",reverse);

}
