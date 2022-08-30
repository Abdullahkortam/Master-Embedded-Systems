/*
 * list.c
 *
 *  Created on: ٢٩‏/٠٨‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#include "list.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "conio.h"

struct SStudent* pgFirstStudent = NULL ;
void addStudent()
{
	struct SStudent* pnewstudent;
	struct SStudent* plaststudent;
	if(!pgFirstStudent)
	{
		pnewstudent = (struct SStudent*)malloc(sizeof(struct SStudent));
		pgFirstStudent = pnewstudent ;
	}
	else
	{
		plaststudent = pgFirstStudent ;
		while(plaststudent->Pnext)
			plaststudent = plaststudent->Pnext ;
		//create new member
		pnewstudent = (struct SStudent*)malloc(sizeof(struct SStudent));
		plaststudent->Pnext = pnewstudent ;
	}

	printf("Enter the ID : \n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&pnewstudent->student.Id);

	printf("Enter the Student Full name : \n");
	fflush(stdin);fflush(stdout);
	gets(pnewstudent->student.name);

	printf("Enter the Height : \n");
	fflush(stdin);fflush(stdout);
	scanf("%f",&pnewstudent->student.height);
	pnewstudent->Pnext = NULL ;
}

int deleteStudent()
{
	int temp_int ;
	printf("Enter the ID to be deleted : \n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&temp_int);

	///check if list is empty
	if(!pgFirstStudent)
	{
		printf("Empty List.\n");
		return 1 ;
	}
	else
	{
		struct SStudent* pSelectedstudent ;
		struct SStudent* pprevstudent= NULL ;
		pSelectedstudent = pgFirstStudent ;

		while(pSelectedstudent)
		{
			if(pSelectedstudent->student.Id == temp_int)
			{
				if(pSelectedstudent == pgFirstStudent)
				{
					pgFirstStudent = pSelectedstudent->Pnext ;
				}
				else
				{
					pprevstudent->Pnext = pSelectedstudent->Pnext ;
				}
				free(pSelectedstudent);
				return (1);
			}
			pprevstudent = pSelectedstudent ;
			pSelectedstudent = pSelectedstudent->Pnext ;
		}
		printf("Error!! Not existed ID.\n");
		return 0 ;
	}
}

void printStudent()
{
	int  i =1;
	struct SStudent* pSelectedstudent ;
	pSelectedstudent =pgFirstStudent ;
	if(!pgFirstStudent)
		printf("Empty list\n");
	else
	{
		while(pSelectedstudent)
		{
			printf("Student No. %d\n",i);
			printf("ID : %d\n",pSelectedstudent->student.Id);
			printf("Name : %s\n",pSelectedstudent->student.name);
			printf("Height : %0.2f\n",pSelectedstudent->student.height);
			i++;
			pSelectedstudent = pSelectedstudent->Pnext ;
		}
	}
}

void DeleteAll()
{
	struct SStudent* pCurrentstudent =pgFirstStudent;
	if(!pgFirstStudent)
		printf("Empty list\n");
	else
	{
		while(pCurrentstudent)
		{
			struct SStudent* ptempstudent = pCurrentstudent ;
			pCurrentstudent = pCurrentstudent->Pnext ;
			free(ptempstudent);
		}
		pgFirstStudent= NULL ;
	}
}
