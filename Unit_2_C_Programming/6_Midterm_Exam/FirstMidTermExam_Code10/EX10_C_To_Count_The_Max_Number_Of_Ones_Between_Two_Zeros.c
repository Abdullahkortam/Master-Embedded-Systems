/*
 * FirstMidTermExam_Code10.c
 *
 *  Created on: ٣١‏/٠٧‏/٢٠٢٢
 *      Author: abdullah kortam
 */

#include <stdio.h>

int NumberOfOnes (int x);

void main()
{
	int num ,no_ones;
	printf("Enter a number:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	no_ones = NumberOfOnes(num);
	printf("Max number of Ones : %d",no_ones);

}

int NumberOfOnes (int x)
{
    int new_num , No_bits= 30 , key =0  ,numberOfOnes=0;

    for(1;No_bits>=0;No_bits--)
    {
        new_num = x >> No_bits ;
        if (new_num & 1)
		{
			key++;
		}
		else
		{
			if(key>numberOfOnes)
			{
				numberOfOnes = key ;
				key = 0;
			}
			else
			{
				key=0;
			}
		}
    }
    return numberOfOnes ;
}
