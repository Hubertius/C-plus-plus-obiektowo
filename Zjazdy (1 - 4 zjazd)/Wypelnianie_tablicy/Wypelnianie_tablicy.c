#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int ** allocate_the_table(int a , int b )
{
    int choice_numberish = choice();
    if( choice_numberish < 0 || choice_numberish > 1 )
    {
        return NULL;
    }
    int number;
    printf("Please write your number from zero to nine below: ");
    if( scanf("%d",&number) != 1 )
    {
        printf("Incorrect input");
        return NULL;
    }
    if( number < 0 || number > 9 )
    {
        printf("Incorrect input data");
        return NULL;
    }
    int ** array = (int **) malloc(sizeof(int *) * a);
    if( array == NULL )
    {
        return NULL;
    }
    int i;
    for(i = 0; i < a; i++)
    {
        *(array + i) = (int *) malloc (sizeof(int) * b);
        if( *(array + i) == NULL )
        {
            destroy(array);
            return NULL;
        }
    }
    int j;
    bool first = true;
    for(i = 0; i < a; i++)
    {
        for(j = 0; j < b; j++)
        {
            if( choice_numberish == 0 )
            {
                *(*(array + i) + j) = number;
            }
            else
            {
                *(*(array + i) + j) = number;
                //printf("%d ",number);
                number++;
            }
        }
    }
    return array;
}
int choice()
{
    printf("Do you want to fill the table with one number or starting from one to the larger and larger?\nChoose 0 or 1: ");
    int choice;
    if( scanf("%d",&choice) != 1)
    {
        printf("Incorrect input");
        return -1;
    }
    if( choice < 0 || choice > 1 )
    {
        printf("Incorrect input data");
        return -2;
    }
    return choice;

}
void destroy( int ** array)
{
    int i = 0;
    while( *(array + i) != NULL )
    {
        free(*(array + i));
        i++;
    }
    free(array);
}
