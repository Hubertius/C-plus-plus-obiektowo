#include <stdio.h>
#include <stdlib.h>
#include "stos.h"

struct my_stack * initialize()
{
    struct my_stack * pointer_on_structure;
    pointer_on_structure = (struct my_stack *) malloc(sizeof(struct my_stack) * 1);
    if(pointer_on_structure == NULL)
    {
        return NULL;
    }
    pointer_on_structure->size = 10;
    int * pointer_on_stracture_table = pointer_on_structure->arr;
    pointer_on_stracture_table = (int *)malloc(sizeof(int) * 10);
    if(pointer_on_stracture_table == NULL)
    {
        free(pointer_on_structure);
        return NULL;
    }
    return  pointer_on_structure;
}
struct my_stack * get_more_size(struct my_stack * pointer_on_structure, int more_size)
{
    if(pointer_on_structure == NULL)
    {
        return NULL;
    }
    pointer_on_structure = (struct my_stack *) realloc(pointer_on_structure,more_size);
    if(pointer_on_structure == NULL)
    {
        return NULL;
    }
    return NULL;
}
int push(struct my_stack * pointer_on_structure, int value)
{
    if( pointer_on_structure == NULL )
    {
        return -2;
    }
    int * pointer_on_table = pointer_on_structure->arr;
    *(pointer_on_table + pointer_on_structure->index) = value;
    int i = pointer_on_structure->index;
    i++;
    pointer_on_structure->index = i;
    return 0;
}
int * pop(struct my_stack * pointer_on_structure, int value) // zwraca wskaźnik na zmienną typu integer
{
    if( pointer_on_structure == NULL )
    {
        return NULL; // kod błędu może mieć taką samą wartość co wartość zdjęta ze stosu.
    }
    int * pointer_on_table = pointer_on_structure->arr;
    int value_to_pop = *(pointer_on_table + pointer_on_structure->index);
    return &value_to_pop;
}
void destroy(struct my_stack * pointer_on_structure)
{
    free(pointer_on_structure->arr);
    free(pointer_on_structure);
}
