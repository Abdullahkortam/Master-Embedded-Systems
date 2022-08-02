/*
 * EX4_C_To_Store_Information_of_Students_Using_Structure.c
 *
 *  Created on: ٠٢‏/٠٨‏/٢٠٢٢
 *      Author: abdullah kortam
 */

#include <stdio.h>

struct Sdata
{
    char m_name[10];
    int m_roll ;
    int m_marks ;
};

struct Sdata scan_structe (struct Sdata a);
void  print (struct Sdata x);

void main()
{
    struct Sdata student[10] ;
    int i ,student_number=10 ;

    printf("Enter information of students:\n");
    for(i=0;i<student_number;i++)
    {
        printf ("\nEnter the information of student No.[%d]:\n", i+1);
        student[i] = scan_structe(student[i]);
    }

    printf("Display information of students:\n");
    for(i=0;i<student_number;i++)
    {
        print(student[i]);
    }


}

struct Sdata scan_structe (struct Sdata a)
{
    struct Sdata sca;
    printf("Enter roll number:");
    fflush(stdin);fflush(stdout);
    scanf("%d",&sca.m_roll);

    printf("Enter name:");
    fflush(stdin);fflush(stdout);
    scanf("%s",sca.m_name);

    printf("Enter marks:");
    fflush(stdin);fflush(stdout);
    scanf("%d",&sca.m_marks);
    return sca ;
}

void print (struct Sdata x)
{
    printf("Enter roll number: %d\n",x.m_roll);
    printf("Enter name: %s\n",x.m_name);
    printf("Enter marks: %d\n",x.m_marks);
}
