/*
 * FirstMidTermExam_Code2.c
 *
 *  Created on: ٣١‏/٠٧‏/٢٠٢٢
 *      Author: abdullah kortam
 */

#include <stdio.h>
#include <math.h>

void root(double x);

void main()
{
	double num ;
	printf("Enter a number:\n");
	fflush(stdin);fflush(stdout);
	scanf("%lf",&num);
	root(num);
}

void root(double x)
{
	double root ;
	root =sqrt(x);
	printf("root of %lf = %lf",x,root);
}
