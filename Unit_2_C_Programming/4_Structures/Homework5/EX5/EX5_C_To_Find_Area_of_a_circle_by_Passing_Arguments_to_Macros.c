/*
 * EX5_C_To_Find_Area_of_a_circle_by_Passing_Arguments_to_Macros.c
 *
 *  Created on: ٠٢‏/٠٨‏/٢٠٢٢
 *      Author: abdullah kortam
 */

#include <stdio.h>

#define pi 3.14159

double cirle_area (double x);

void main()
{
    double radius  ,area;
    printf("Enter the radius:\n");
    fflush(stdin);fflush(stdout);
    scanf("%lf",&radius);
    area=cirle_area(radius);
    printf("Area = %0.2lf",area);
}
double cirle_area (double x)
{
    return (x * pi * x);
}
