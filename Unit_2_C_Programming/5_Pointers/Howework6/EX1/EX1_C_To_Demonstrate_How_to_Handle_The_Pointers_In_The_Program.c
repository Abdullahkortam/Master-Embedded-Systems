/*
 * EX1_C_Program_to_Demonstrate_How_to_Handle_the_Pointers_in_the_Program.c
 *
 *  Created on: ٠٧‏/٠٨‏/٢٠٢٢
 *      Author: abdullah kortam
 */

#include <stdio.h>

void main()
{
	 int num;
	    int *p ;
	    num = 29 ;
	    printf("Address of num : 0x%p\n",&num);
	    printf("Value of num : %d\n\n",num);

	    p=&num ;
	    printf("Now p is assigned with the address of num.\n");
	    printf("Address of pointer p : 0x%p\n",p);
	    printf("content of pointer p : %d\n\n",*p);

	    num = 34 ;
	    printf("The value of num assigned to 34 now.\n");
	    printf("Address of pointer p : 0x%p\n",p);
	    printf("content of pointer p : %d\n\n",*p);

	    *p = 7 ;
	    printf("The pointer variable p is assigneg with the value 7 now.\n");
	    printf("Address of num : 0x%p\n",&num);
	    printf("Value of num : %d\n\n",num);
}
