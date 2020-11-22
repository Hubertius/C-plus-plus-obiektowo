#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    printf("Please write your first string: ");
    char first[1000];
    scanf("%[^\n]s",first);
    printf("Please write your second string: ");
    char second[1000];
    //while(getchar() != '\n' );
    scanf(" %[^\n]s",second);
    int a = strlen(first);
    printf("%s   and   %s\n",first,second);
    int b = strlen(second);
    int c = a + b ;
    char * pointer_on = (char *) malloc((a + b + 1) * sizeof(char));
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
    printf("%s",pointer_on);
    free(pointer_on);
    return 0;
}
