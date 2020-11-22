#include <stdio.h>
#include <stdlib.h>
#include "Wypelnianie_tablicy.h"

int main()
{
    int a = 3, b = 4;
    int ** pointer = allocate_the_table(a,b);
    if( pointer == NULL )
    {
        printf("\nERROR!!!!");
        return 1;
    }
    else
    {
        int i,j;
        for(i = 0; i < a; i++)
        {
            for(j = 0; j < b; j++)
            {
                printf("%d ",*(*(pointer + i) + j));
            }
            printf("\n");
        }
    }
    destroy(pointer);
    return 0;
}
