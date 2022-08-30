/*
 * list.c
 *
 *  Created on: ٢٩‏/٠٨‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "list.h"

struct list *Head ;

void AddNode()
{
	struct list* NewNode ;
	struct list* LastNode ;
	//First Node
	if(!Head)
	{
		NewNode = (struct list*)malloc(sizeof(struct list));
		Head = NewNode ;
	}
	else
	{
		LastNode = Head ;
		while(LastNode->next)
			LastNode = LastNode->next ;

		NewNode = (struct list*)malloc(sizeof(struct list));
		LastNode->next = NewNode ;
	}
	printf("Enter Node Data :\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&NewNode->data);

	NewNode->next = NULL ;
}

void PrintList()
{
	int i =1 ;
	struct list* SelestedNode;
	if(!Head)
		printf("Empty List!!\n");
	else
	{
		SelestedNode = Head ;
		while(SelestedNode)
		{
			printf("Node %d Data : %d\n",i,SelestedNode->data);
			SelestedNode = SelestedNode->next ;
			i++ ;
		}
	}
}

void DeleteNode()
{
	struct list* CurrentNode= Head ;
	struct list* PrevNode =NULL;
	int U_data ;
	printf("Enter Node Data to delete : \n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&U_data);

	if(!Head)
		printf("Empty List!!\n");
	else
	{
		if(CurrentNode->data == U_data)
		{
			Head = CurrentNode->next ;
		}
		else
		{
			while(CurrentNode)
			{
				if(CurrentNode->data == U_data)
				{
					PrevNode->next = CurrentNode->next ;
					free(CurrentNode);
					break;
				}
				else
				{
					PrevNode = CurrentNode;
					CurrentNode = CurrentNode->next ;
				}
			}
		}
	}
}

void GetNth()
{
	int count ,i =1;
	printf("Enter the Nth Element : \n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&count);

	struct list* CurrentNode =Head ;

	while(count!=i)
	{
		CurrentNode = CurrentNode->next ;
		i++ ;
	}
	printf("The %dth data = %d\n",count,CurrentNode->data);
}

int Length_iterative()
{
	int count=0 ;
	struct list* CurrentNode =Head ;

	while(CurrentNode)
	{
		CurrentNode = CurrentNode->next ;
		count++ ;
	}
	return count ;
}

int Length_recursive(struct list* list)
{
	static int i = 1 ;
	if(i==1)
	{
		list = Head;
		i++ ;
	}
	if(Head == NULL )
	{
		return 0;
	}

	if(list == NULL)
	{
		i=1 ;
		return 0;
	}
	else
	{
		return 1+Length_recursive(list->next);
	}
}

int GETNode(int num)
{
	int count=1 ;
	struct list* CurrentNode =Head ;
	while(count!= num)
	{
		CurrentNode = CurrentNode->next ;
		count ++ ;
	}
	return CurrentNode->data ;
}

void GetNthFEnd()
{
	int len , num ;
	printf("Enter the Nth node from the end:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	len =Length_iterative();
	int data =GETNode(len-num+1);
	printf("The %dth Node from End : %d\n",num,data);
}

void GetMiddleNode()
{
	int len , data ;
	len = Length_iterative();
	if(len %2 ==0)
		data=GETNode(len/2);
	else
		data=GETNode(len/2+1);
	printf("Middle Node -> Data : %d\n",data);
}

void ReverseList()
{
	struct list* CurrentNode = Head ;
	struct list* PrevNode = NULL ;
	struct list* NextNode = NULL ;

	if(!Head)
	{
		printf("Empty List!!\n");
		return ;
	}

	while(CurrentNode)
	{
		NextNode = CurrentNode->next ;
		CurrentNode->next = PrevNode ;
		PrevNode = CurrentNode ;
		CurrentNode = NextNode ;
	}
	Head = PrevNode ;
}

void DeleteAll()
{
	struct list* CurrentNode = Head;
	if(!Head)
		printf("Empty list\n");
	else
	{
		while(CurrentNode)
		{
			struct list* tempNode = CurrentNode ;
			CurrentNode = CurrentNode->next ;
			free(tempNode);
		}
		Head= NULL ;
	}
}
