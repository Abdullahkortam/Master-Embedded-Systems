/*
 * EX3_C_To_Add_Two_Complex_Numbers_By_Passing_Structure_To_a_Function.c
 *
 *  Created on: ٠٢‏/٠٨‏/٢٠٢٢
 *      Author: mkm
 */

#include <stdio.h>

struct Scomplexnumber
{
    float m_real ;
    float m_imag ;
};

struct Scomplexnumber scan_structe (struct Scomplexnumber a);
struct Scomplexnumber sum (struct Scomplexnumber a,struct Scomplexnumber b);

void main()
{
    struct Scomplexnumber num1 ;
    struct Scomplexnumber num2 ;
    struct Scomplexnumber sum1 ;

    printf("For 1st complex number:\n");
    printf("Enter real and imaginary respectively:");
    num1 = scan_structe(num1);

    printf("For 2nd complex number:\n");
    printf("Enter real and imaginary respectively:");
    num2 = scan_structe(num2);

    sum1 = sum(num1,num2);
    printf("sum = %0.1f+%0.1fi",sum1.m_real,sum1.m_imag);
}
struct Scomplexnumber scan_structe (struct Scomplexnumber a)
{
    struct Scomplexnumber sca;
    fflush(stdin);fflush(stdout);
    scanf("%f",&sca.m_real);

    fflush(stdin);fflush(stdout);
    scanf("%f",&sca.m_imag);
    return sca ;
}
struct Scomplexnumber sum (struct Scomplexnumber a,struct Scomplexnumber b)
{
    struct Scomplexnumber sum ;
    sum.m_real = a.m_real + b.m_real;
    sum.m_imag = a.m_imag + b.m_imag ;

    return sum ;
}
