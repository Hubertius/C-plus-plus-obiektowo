#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input(char first[],char second[])
{
    printf("Please write your first string: ");
    scanf("%[^\n]s",first);
    printf("Please write your second string: ");
    scanf(" %[^\n]s",second);
}
char * concatenate(char first[], char second[])
{
    int a = strlen(first);
    printf("%s   and   %s\n",first,second);
    int b = strlen(second);
    int c = a + b ;
    char * pointer_on = (char *) malloc((a + b + 1) * sizeof(char));
    if( pointer_on == NULL )
    {
        return NULL;
    }
    int i;
    for(i = 0; i < a; i++)
    {
        *(pointer_on + i) = *(first + i);
    }
    int j = 0;
    for(i = a; i < c; i++)
    {
        *(pointer_on + i) = *(second + j);
        j++;
    }
    *(pointer_on + c) = '\0';
    return pointer_on;
}
