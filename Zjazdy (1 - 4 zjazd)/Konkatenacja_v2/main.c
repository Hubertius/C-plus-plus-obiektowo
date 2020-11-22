#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Konkatenacja.h"
int main()
{
    char first[1000];
    char second[1000];
    input(first,second);
    char * pointer = concatenate(first,second);
    if( pointer == NULL )
    {
        return 2;
    }
    printf("%s",pointer);
    free(pointer);
    return 0;
}
