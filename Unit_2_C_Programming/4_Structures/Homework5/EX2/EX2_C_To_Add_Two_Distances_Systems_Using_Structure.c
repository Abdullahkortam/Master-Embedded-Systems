/*
 * EX1+C_To_Add_Two_Distances_Systems_Using_Structure.c
 *
 *  Created on: ٠٢‏/٠٨‏/٢٠٢٢
 *      Author: mkm
 */

#include <stdio.h>

struct Sdistance
{
    int m_feet ;
    float m_inch ;
};

struct Sdistance sum (struct Sdistance a,struct Sdistance b);
struct Sdistance scan_structe (struct Sdistance a);

void main()
{
    struct Sdistance read1 ;
    struct Sdistance read2 ;
    printf("Enter information for 1st distance:\n");
    read1 = scan_structe(read1);
    printf("Enter information for 2nd distance:\n");
    read2 = scan_structe(read2);

    read1 = sum(read1,read2);
    printf("Sum of distance =%d'-%0.2f\"",read1.m_feet,read1.m_inch);
}

struct Sdistance sum (struct Sdistance a,struct Sdistance b)
{
    struct Sdistance sum ;
    sum.m_feet = a.m_feet + b.m_feet;
    sum.m_inch = a.m_inch + b.m_inch ;

    if(sum.m_inch >=12)
    {
        ++sum.m_feet ;
        sum.m_inch-=12.0 ;
    }
    return sum ;
}
struct Sdistance scan_structe (struct Sdistance a)
{
    struct Sdistance sca;
    printf("Enter feet:");
    fflush(stdin);fflush(stdout);
    scanf("%d",&sca.m_feet);

    printf("Enter inch:");
    fflush(stdin);fflush(stdout);
    scanf("%f",&sca.m_inch);
    return sca ;
}
