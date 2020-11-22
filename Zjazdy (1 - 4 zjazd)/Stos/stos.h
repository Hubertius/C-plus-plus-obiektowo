#ifndef STOS_H_INCLUDED
#define STOS_H_INCLUDED

struct my_stack{
    int size; // ile elementow mozna obecnie zamiescic na stosie
    int index; // indeks ostatniego elementu na stosie
    int *arr; // wartosci dla elementow na stosie
};

struct my_stack * initialize();
struct my_stack * get_more_size(struct my_stack * pointer_on_structure, int more_size);
int push(struct my_stack * pointer_on_structure, int value);
int * pop(struct my_stack * pointer_on_structure, int value);
void destroy(struct my_stack * pointer_on_structure);
#endif // STOS_H_INCLUDED
