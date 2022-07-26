/*
 * EX3_C_To_Find_Transpose_Of_Matrix.c
 *
 *  Created on: ٢٦‏/٠٧‏/٢٠٢٢
 *      Author: mkm
 */

#include "stdio.h"

void main()
{
	int row , column ;
	int i ,j;
	int matrix[100][100] , matrix_t[100][100];

	printf("Enter rows and colum of Matrix: ");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&row,&column);

	printf("Enter elemnts of matrix:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			printf("Enter element a%d%d: ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%d",&matrix[i][j]);
		}
	}

	//get_transpose
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			matrix_t[j][i] = matrix[i][j];
		}
	}

	//print Original Matrix
	printf("Entered Matrix:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			printf("%d\t",matrix[i][j]);
			if(j==column-1)
				printf("\n");
		}
	}

	//print Transpose Matrix
	printf("\nTranspose of Matrix:\n");
	for(i=0;i<column;i++)
	{
		for(j=0;j<row;j++)
		{
			printf("%d\t",matrix_t[i][j]);
			if(j==row-1)
				printf("\n");
		}
	}


}
