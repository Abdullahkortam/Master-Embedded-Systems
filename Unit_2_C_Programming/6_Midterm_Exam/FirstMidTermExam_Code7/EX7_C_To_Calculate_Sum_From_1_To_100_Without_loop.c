/*
 * FirstMidTermExam_Code7.c
 *
 *  Created on: ٣١‏/٠٧‏/٢٠٢٢
 *      Author: abdullah kortam
 */
#include "stdio.h"

void main()
{
    static  int num = 0 , sum=0;
	if(num<=100)
	{
        sum+= num ;
        num ++;
        main();
	}
    if(num==101)
        printf("Sum = %d",sum);
        num++ ;
}
