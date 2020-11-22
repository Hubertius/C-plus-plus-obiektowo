#include <iostream>
#include "stos.h"

using namespace std;

Stos::Stos(int size_default = 10)
{
	size = size_default;
	index = 0;
	arr = (int*)malloc(sizeof(int) * size); // alokacja pamięci przy zainicjowaniu obiektu klasy "Stos"
}
Stos::~Stos()
{
	free(arr);
}

bool Stos::check_for_expand()
{
	if (size == index)
	{
		return true;
	}
	return false;
}

bool Stos::check_for_take_away()
{
	if (index == 0)
	{
		return true;
	}
	return false;
}

int * Stos::expandHeap()
{
	int* pointer;
	size += 10;
	pointer = (int*)realloc(arr, sizeof(int) * size);
	if (pointer == NULL)
	{
		return NULL;
	}
	else
	{
		arr = pointer;
	}
}

void Stos::push(int value_for_push)
{
	if (size == index)
	{

	}
	*(arr + index) = value_for_push;
	index++;
}

int Stos::pop()
{
	index--;
	int value_for_pop = *(arr + index);
	return value_for_pop;
}

void Stos::display_elements()
{
	if (index != 0)
	{
		for (int i = 0; i < index; i++)
		{
			cout << *(arr + i) << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "Heap is empty." << endl;
	}
}

int Stos::count_elements()
{
	return index;
}

