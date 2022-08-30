/*
 * list.h
 *
 *  Created on: ٢٩‏/٠٨‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#ifndef LIST_H_
#define LIST_H_
#include <stdlib.h>
struct Sdata
{
	int Id ;
	char name[40] ;
	float height ;
};

struct SStudent
{
	struct Sdata student ;
	struct SStudent* Pnext ;
};

void addStudent();
int deleteStudent();
void printStudent();
void DeleteAll();
#endif /* LIST_H_ */
