/************************************************************************************************************
 *  main.c
 *  First_Term_project C
 *  Created on: ٠٣‏/٠٩‏/٢٠٢٢
 *  Author: Abdullah Kortam
 ***********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"

int main()
{
	int flag ;
	printf("Welcome To The Student Management System\n");
	while(1)
	{
		printf("---------------------------------\n");
		printf("Choose You option :\n");
		printf("1) Add Student Manually\n");
		printf("2) Add Student From Text File\n");
		printf("3) Find Student by Roll Number\n");
		printf("4) Find Student by First Name\n");
		printf("5) Find Student by Course ID\n");
		printf("6) Find The Total Number Of Students\n");
		printf("7) Delete Student by Roll Number\n");
		printf("8) Update Student by Roll Number\n");
		printf("9)Show All Information\n");
		printf("10)Exit\n");
		printf("Enter Option No. :");
		fflush(stdin);fflush(stdout);
		scanf("%d",&flag);
		printf("---------------------------------\n");

		switch(flag)
		{
		case 1 :
			add_student_manually();
			break;
		case 2 :
			add_student_file();
			break;
		case 3 :
			find_rl();
			break;
		case 4 :
			find_fn();
			break;
		case 5 :
			find_c();
			break;
		case 6 :
			tot_S();
			break;
		case 7 :
			del_s();
			break;
		case 8 :
			up_s();
			break;
		case 9 :
			show_s();
			break;
		case 10 :
			printf("End Of The Program..");
			exit(0);
			break;
		default:
			printf("Wrong Input\n");
			break ;
		}
	}
	return 0 ;
}
