/************************************************************************************************************
 *  fifo.h
 *  First_Term_project C
 *  Created on: ٠٣‏/٠٩‏/٢٠٢٢
 *  Author: Abdullah Kortam
 ***********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fifo.h"
struct fifo* Head = NULL ;
struct fifo* LastNode =NULL ;
struct  sinfo st[55];
int  i =0 ;

void add_student_manually()
{
	struct fifo* NewNode ;

	//first Node
	if(!Head)
	{
		NewNode = (struct fifo*)malloc(sizeof(struct fifo));
		NewNode->next = NULL ;
		NewNode->p = &st[i] ;
		i++ ;
		if(fillstr(NewNode->p)==student_failed)
		{
			free(NewNode);
			i--;
		}
		else
		{
			Head = NewNode ;
			LastNode = NewNode ;
		}
	}
	else
	{
		NewNode = (struct fifo*)malloc(sizeof(struct fifo));
		NewNode->p = & st[i] ;
		i++ ;
		if(fillstr(NewNode->p)==student_failed)
		{
			free(NewNode);
			i-- ;
		}
		else
		{
			LastNode->next =NewNode ;
			LastNode = NewNode ;
			LastNode->next = NULL ;
		}
	}
	tot_S();
	printf("[INFO] You Can add %d Student more\n",55-i);
}

//Check if the roll number is duplicated.
status rollcheck(int x)
{
	struct fifo* temp = Head;
	if(!Head)
		return student_successfully ;
	else
	{
		while(temp)
		{
			if(temp->p->roll == x)
			{
				return 	student_failed ;
				break ;
			}
			temp = temp->next;
		}
	}
	return student_successfully ;
}

//fill the data of the Student
status fillstr(struct sinfo* st)
{
	int j = 0 ;
	printf("Enter The Roll Number:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&st->roll);
	if(rollcheck(st->roll) == student_failed)
	{
		printf("[INFO] Roll Number %d is taken\n",st->roll);
		return student_failed ;
	}

	printf("Enter first Name:");
	fflush(stdin);fflush(stdout);
	gets(st->fname);

	printf("Enter Last Name:");
	fflush(stdin);fflush(stdout);
	gets(st->lname);

	printf("Enter The GPA:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&st->GPA);

	printf("Enter The number of courses:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&st->NoCourse);

	printf("Enter The Course ID of each course :\n");
	for(j=0;j<st->NoCourse;j++)
	{
		printf("Enter course %d ID : ",j+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",&st->cid[j]);
	}

	printf("[INFO] Student is added Successfully\n");
	return student_successfully ;
}

void add_student_file()
{
	int j;
	char FileName[20] ;
	printf("Enter The File Name(.txt)\n");
	fflush(stdin);fflush(stdout);
	gets(FileName);
	FILE *ptr ;

	ptr= fopen("file.txt","r");

	if(ptr == NULL)
	{
		printf("Open File Failed\n");
		fclose(ptr);
	}
	char retChar;
	while ((retChar = fgetc(ptr)) != EOF)
	{
		struct fifo* NewNode =  file_handle();
		fflush(stdin);fflush(stdout);
		fscanf(ptr,"%d",&NewNode->p->roll );

		if(duplicate(NewNode->p->roll) ==student_failed)
		{
			printf("[INFO] Roll Number %d is taken\n",NewNode->p->roll);
			free(NewNode);
			i--;
			fflush(stdin);fflush(stdout);
			fscanf(ptr,"%*[^\n\b]\b\n");
			continue ;
		}
		printf("[INFO] Roll Number %d saved successfully\n",NewNode->p->roll);
		fflush(stdin);fflush(stdout);
		fscanf(ptr, "%s",NewNode->p->fname);
		fflush(stdin);fflush(stdout);
		fscanf(ptr, "%s",NewNode->p->lname);
		fflush(stdin);fflush(stdout);
		fscanf(ptr, "%f",&NewNode->p->GPA);
		fflush(stdin);fflush(stdout);
		fscanf(ptr, "%d",&NewNode->p->NoCourse);
		for(j=0;j<LastNode->p->NoCourse;j++)
		{
			fflush(stdin);fflush(stdout);
			fscanf(ptr, "%d",&NewNode->p->cid[j]);
		}
		NewNode->next = NULL ;
	}
	printf("[INFO] Students details are saved successfully\n");
	tot_S();
	printf("[INFO] You Can add %d Student more\n",55-i);
	return ;
	fclose(ptr);
}

struct fifo* file_handle()
{
	struct fifo* NewNode ;
	if(!Head)
	{
		NewNode = (struct fifo*)malloc(sizeof(struct fifo));
		NewNode->next = NULL ;
		NewNode->p = &st[i];
		i++ ;
		Head = NewNode ;
		LastNode = NewNode ;
		return LastNode;
	}
	else
	{
		NewNode = (struct fifo*)malloc(sizeof(struct fifo));
		NewNode->next = NULL ;
		NewNode->p = &st[i];
		i++ ;
		LastNode->next = NewNode ;
		LastNode= NewNode ;
		LastNode->next = NULL;
		return LastNode ;
	}
}

void find_rl()
{
	int roll , j =0 , flag =0 ;
	struct fifo* temp = Head;
	if(!Head)
	{
		printf("Empty DATABASE!!!\n");
		return ;
	}
	printf("Enter the roll number:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&roll);

	while(temp)
	{
		if(temp->p->roll == roll)
		{
			flag ++ ;
			printf("Student's details are:\n");
			printf("The first Name : %s\n",temp->p->fname);
			printf("The last Name : %s\n",temp->p->lname);
			printf("The GPA: %0.2f\n",temp->p->GPA);
			for(j=0;j<temp->p->NoCourse;j++)
			{
				printf("Course %d ID : %d \n",j+1,temp->p->cid[j]);
			}
			printf("---------------------------------\n");
		}
		temp = temp->next;
	}
	if(flag == 0)
		printf("Roll Number %d Not Found.\n",roll);
}

void find_fn()
{
	int j =0 , flag =0 ;
	char ch[50];
	struct fifo* temp = Head;
	if(!Head)
	{
		printf("Empty DATABASE!!!\n");
		return ;
	}
	printf("Enter the First Name:\n");
	fflush(stdin);fflush(stdout);
	gets(ch);
	while(temp)
	{
		if(strcmp(temp->p->fname,ch)==0)
		{
			flag ++ ;
			printf("Student's details are:\n");
			printf("The Roll Number : %d\n",temp->p->roll);
			printf("The first Name : %s\n",temp->p->fname);
			printf("The last Name : %s\n",temp->p->lname);
			printf("The GPA: %0.2f\n",temp->p->GPA);
			for(j=0;j<temp->p->NoCourse;j++)
			{
				printf("Course %d ID : %d \n",j+1,temp->p->cid[j]);
			}
			printf("---------------------------------\n");
		}
		temp = temp->next;
	}
	if(flag == 0)
		printf("First Name %s Not Found.\n",ch);
}

void find_c()
{
	int id , j =0 , flag =0 , count =0  ;
	struct fifo* temp = Head;
	if(!Head)
	{
		printf("Empty DATABASE!!!\n");
		return ;
	}
	printf("Enter the Course ID:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&id);

	while(temp)
	{
		for(j=0;j<temp->p->NoCourse;j++)
		{
			if(temp->p->cid[j] == id)
			{
				flag =1 ;
				count ++ ;
				printf("Student's details are:\n");
				printf("The Roll Number : %d\n",temp->p->roll);
				printf("The first Name : %s\n",temp->p->fname);
				printf("The last Name : %s\n",temp->p->lname);
				printf("The GPA: %0.2f\n",temp->p->GPA);
			}
		}
		temp = temp->next;
	}
	if(flag == 0)
		printf("ID Number %d Not Found.\n",id);
	else
		printf("Number of the Student in Course (ID = %d) : %d\n",id,count);
}

void tot_S()
{
	int count = 0 ;
	struct fifo* CurrentNode = Head ;
	if(!Head)
	{
		count = 0 ;
	}
	else
	{
		while(CurrentNode)
		{
			count ++ ;
			CurrentNode = CurrentNode->next ;
		}
	}
	printf("[INFO] The Total Number Of Student : %d\n",count);
}

void del_s()
{
	int roll  ,flag =0;
	struct fifo* CurrentNode= Head ;
	struct fifo* PrevNode =NULL;
	printf("Enter the roll number:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&roll);
	if(!Head)
		printf("Empty List!!\n");
	else
	{
		if(CurrentNode->p->roll == roll)
		{
			flag = 1 ;
			Head = Head->next ;
			i--;
			free(CurrentNode);
			printf("=====Delete Done=====\n");
		}
		else
		{
			while(CurrentNode)
			{
				if(CurrentNode->p->roll == roll)
				{
					flag =1 ;
					PrevNode->next = CurrentNode->next ;
					i--;
					free(CurrentNode);
					printf("=====Delete Done=====\n");
					break;
				}
				else
				{
					PrevNode = CurrentNode;
					CurrentNode = CurrentNode->next ;
				}
			}
		}
		tot_S();
		printf("[INFO] You Can add %d Student more\n",55-i);
	}

	if(flag ==0)
		printf("Roll Number %d Not Found.\n",roll);
}

void up_s()
{
	int roll , flag =0 , choise = 0 , x, check =1 , j=0;
	struct fifo* temp = Head;
	if(!Head)
	{
		printf("Empty DATABASE!!!\n");
		return ;
	}
	printf("Enter the roll number:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&roll);

	while(temp)
	{
		if(temp->p->roll == roll)
		{
			flag ++ ;
			printf("Enter The Roll Number To Update The Task :\n");
			printf("1) First Name\n");
			printf("2) Last Name\n");
			printf("3) Roll Number\n");
			printf("4) GPA \n");
			printf("5) Courses\n");
			printf("Enter Option No. :");
			fflush(stdin);fflush(stdout);
			scanf("%d",&choise);
			switch(choise)
			{
			case 1 :
				fflush(stdin);fflush(stdout);
				gets(temp->p->fname);
				break ;
			case 2 :
				fflush(stdin);fflush(stdout);
				gets(temp->p->lname);
				break ;
			case 3 :
				fflush(stdin);fflush(stdout);
				scanf("%d",&x);
				if(rollcheck(x) == student_successfully)
					temp->p->roll = x;
				else
				{
					printf("Failed!!!! , Used Roll Number\n");
					return;
				}
				break ;
			case 4 :
				fflush(stdin);fflush(stdout);
				scanf("%f",&temp->p->GPA);
				break ;
			case 5 :
				printf("Enter the new number of Course\n");
				fflush(stdin);fflush(stdout);
				scanf("%d",&temp->p->NoCourse);
				printf("Enter All the Course :\n");
				for(j=0;j<temp->p->NoCourse;j++)
				{
					fflush(stdin);fflush(stdout);
					scanf("%d",&temp->p->cid[j]);
				}
				break ;
			}
		}
		temp = temp->next;
	}
	if(flag == 0)
		printf("Roll Number %d Not Found.\n",roll);
	else if(check != 0)
		printf("UPDATED SUCCESSFULLY\n");
}

//print all queue
void show_s()
{
	int j =0 ;
	struct fifo* temp ;
	temp = Head ;
	if(!Head)
		printf("Queue is empty\n");
	else
	{
		while(temp)
		{
			printf("The Roll Number: %d\n",temp->p->roll);
			printf("The first Name : %s\n",temp->p->fname);
			printf("The last Name : %s\n",temp->p->lname);
			printf("The GPA: %0.2f\n",temp->p->GPA);
			for(j=0;j<temp->p->NoCourse;j++)
			{
				printf("Course %d ID : %d \n",j+1,temp->p->cid[j]);
			}
			printf("---------------------------------\n");
			temp = temp->next;
		}
	}
}

status duplicate(int x)
{
	struct fifo* temp = Head;
	if(!Head)
		return student_successfully ;
	else
	{
		while(temp)
		{
			if(temp->p->roll == x && temp!=LastNode)
			{
				return 	student_failed ;
				break ;
			}
			temp = temp->next;
		}
	}
	return student_successfully ;
}
