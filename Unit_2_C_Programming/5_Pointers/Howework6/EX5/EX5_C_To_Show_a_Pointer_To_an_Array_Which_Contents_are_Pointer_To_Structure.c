/*
 * EX5_C_To_Show_a_Pointer_To_an_Array_Which_Contents_are_Pointer_To_Structure.c
 *
 *  Created on: ٠٧‏/٠٨‏/٢٠٢٢
 *      Author: abdullah kortam
 */

#include <stdio.h>

struct SEmployee
{
	char m_name[20];
	int id;
};
void main()
{
	struct SEmployee emp[3] ={{"Abdullah",22},{"Mostafa",25},{"Eslam",23}};
	struct SEmployee* pointer = &emp ;
	printf("Employee name %s\n",pointer->m_name);
	printf("Employee ID : %d\n",pointer->id);

}
