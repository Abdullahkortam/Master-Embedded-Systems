/*
 * main.c
 *
 *  Created on: ٢٩‏/٠٨‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#include <stdio.h>
#include "list.h"

struct list* gstruct ;
int main()
{
	int flag , len;

	while(1)
	{
		printf("==================================\n");
		printf("Choose You option :\n");
		printf("1) Add Student\n");
		printf("2) Delete Student\n");
		printf("3) View All\n");
		printf("4) Get Nth\n");
		printf("5) Length_iterative\n");
		printf("6) Length_recursive\n");
		printf("7) Get Nth from the end\n");
		printf("8) Get Middle Node\n");
		printf("9) Reverse List\n");
		printf("10) Delete ALL\n");
		printf("Enter Option No. :");
		fflush(stdin);fflush(stdout);
		scanf("%d",&flag);
		printf("==================================\n");

		switch(flag)
		{
		case 1 :
			AddNode();
			break;
		case 2 :
			DeleteNode();
			break;
		case 3 :
			PrintList();
			break;
		case 4 :
			GetNth();
			break;
		case 5 :
			len =Length_iterative();
			printf("List Length : %d\n",len);
			break;
		case 6 :
			len =Length_recursive(gstruct);
			printf("List Length : %d\n",len);
			break;
		case 7 :
			GetNthFEnd();
			break;
		case 8 :
			GetMiddleNode();
			break;
		case 9 :
			ReverseList();
			break;
		case 10 :
		    DeleteAll();
			break;
		default:
			printf("Wrong Input\n");
			break ;
		}
	}
	return 0 ;
}
