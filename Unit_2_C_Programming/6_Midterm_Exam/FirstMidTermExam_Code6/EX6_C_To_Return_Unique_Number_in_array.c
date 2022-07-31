/*
 * FirstMidTermExam_Code6.c
 *
 *  Created on: ٣١‏/٠٧‏/٢٠٢٢
 *      Author: abdullah kortam
 */
#include <stdio.h>

int main()
{
    int arr[10], freq[10];
    int size, i, j, count;

    printf("Enter size of array: ");
    fflush(stdout); fflush(stdin);
    scanf("%d", &size);


    fflush(stdout); fflush(stdin);
    for(i=0; i<size; i++)
    {
        printf("Enter elements %d: ",i+1);
        fflush(stdout); fflush(stdin);
        scanf("%d", &arr[i]);
        freq[i] = -1;
    }

    for(i=0; i<size; i++)
    {
        count = 1;
        for(j=i+1; j<size; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                freq[j] = 0;
            }
        }

        if(freq[i] != 0)
        {
            freq[i] = count;
        }
    }


    for(i=0; i<size; i++)
    {
        if(freq[i] == 1)
        {
            printf("\nUnique elements is %d",arr[i]);
        }
    }

    return 0;
}
