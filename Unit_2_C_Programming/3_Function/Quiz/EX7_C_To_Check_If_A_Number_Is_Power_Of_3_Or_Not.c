/*
 *
 * EX7_C_To_Check_If_A_Number_Is_Power_Of_3_Or_Not.c
 *
 *  Created on: ٣٠‏/٠٧‏/٢٠٢٢
 *      Author: Abdullah Kortam
 */

#include <Stdio.h>

int check (int x);

void main()
{
    int num ;
    printf("Enter a number:\n");
    fflush(stdin);fflush(stdout);
    scanf("%d",&num);
    int c = check(num);
    printf("%d >>>> %d",num,c);

}
int check (int x)
{
	double flag = log(x) / log(3);
	if(flag == trunc(flag))
		return 1 ;
	else
		return 0;
}

