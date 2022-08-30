/*
 * main.c
 *
 *  Created on: ٢٩‏/٠٨‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#include <stdio.h>
#include "list.h"

int main()
{
	int flag ;

	while(1)
	{
		printf("==================================\n");
		printf("Choose You option :\n");
		printf("1) Add Student\n");
		printf("2) Delete Student\n");
		printf("3) View All\n");
		printf("4) Delete ALL\n");
		printf("Enter Option No. :");
		fflush(stdin);fflush(stdout);
		scanf("%d",&flag);
		printf("==================================\n");

		switch(flag)
		{
		case 1 :
			addStudent();
			break;
		case 2 :
			deleteStudent();
			break;
		case 3 :
			printStudent();
			break;
		case 4 :
			DeleteAll();
			break;
		default:
			printf("Wrong Input\n");
			break ;
		}
	}
	return 0 ;
}


