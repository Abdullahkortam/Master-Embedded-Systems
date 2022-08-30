/*
 * list.h
 *
 *  Created on: ٢٩‏/٠٨‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#ifndef LIST_H_
#define LIST_H_

struct list
{
	int data ;
	struct list* next ;
};

void AddNode();
void PrintList();
void DeleteNode();
void DeleteAll();
void GetNth();
int  Length_iterative();
int  Length_recursive(struct list* Head);
int  GETNode(int num);
void GetNthFEnd();
void GetMiddleNode();
void ReverseList();
#endif /* LIST_H_ */
