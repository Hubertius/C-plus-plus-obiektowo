#include <iostream>
#include "stos.h"
using namespace std;
/*
	------------------------------------------------------------NOTKA DOKUMENTACYJNA------------------------------------------------------------------------------------------------
	PL

	wciśnij: 0 - zakończenie programu
	wciśnij: 1 - dodaj element na stos
	wciśnij: 2 - zabierz element ze stosu
	wciśnij: 3 - odczytywanie wartosci elementow na stosie
	wciśnij: 4 - sprawdź ile elementów znajduje się na stosie

	ANG
	
	click: 0 - end of the program
	click: 1 - add element to the heap_1
	click: 2 - take element from the heap_1
	click: 3 - read all values of the elements from the heap_1
	click: 4 - check how many elements is on the heap_1.

	------------------------------------------------------------NOTKA DOKUMENTACYJNA------------------------------------------------------------------------------------------------
*/

int main()
{
	Stos heap_1(10);
	int choice = -1;
	do
	{
		cout << "Write your choice (0-4): ";
		if (!(cin >> choice)) // Zabezpieczenie na wypadek, gdyby nie została podana przez użytkownika liczba.
		{
			cout << "Incorrect input";
			return 1;
		}
		else
		{
			if (choice < 0 || choice > 4) // Zabezpieczenie przed złym wprowadzeniem przez użytkownika "liczby sterującej" (czyli mniejszej od 0 lub większej od 3) w programie. 
			{
				cout << "Incorrect input data";
				return 2;
			}
		}
		;
		if (choice == 1) // Dodanie elementu do stosu.
		{
			cout << "Write your value, which you want to be up on the heap_1: ";
			int value;
			if (!(cin >> value)) // Zabezpieczenie na wypadek, gdyby nie została podana przez użytkownika liczba.
			{
				cout << "Incorrect input";
				return 1;
			}
			else
			{
				bool check_if_needed_expand = heap_1.check_for_expand(); // Wywołanie metody check_for_expand(), dzięki której sprawdzam czy istnieje potrzeba "zwiększenia stosu" (czyli tablicy arr)
				if (check_if_needed_expand == true)
				{
					int* pointer = heap_1.expandHeap();
					if (pointer == NULL) // jeżeli realokacja się nie powiedzie program zakończy się z kodem błędu 8, a destruktor zwolni pamięć z int * arr.
					{
						cout << "Failed to allocate memory";
						return 8;
					}
				}
				heap_1.push(value);
			}
		}
		else if (choice == 2) // Zabranie elementu ze stosu
		{
			bool check_for_pop = heap_1.check_for_take_away();
			if (check_for_pop == true) // Nie mozna zrobic pop, bo pierwsze wolne miejsce na stosie to index = 0, a wiec nie ma co zabrac ze stosu!
			{
				cout << "heap_1 is empty. Sorry. :(" << endl;
				continue;
			}
			else // Mozna zrobic pop, bo index > 0, a wiec jest co zabrac ze stosu.
			{
				int value;
				value = heap_1.pop(); // wywołanie metody pop()
				cout << "Value, which you wanted to be pop out: " << value << endl;
			}
		}
		else if (choice == 3) // odczytywanie wartosci wszystkich elementow na stosie
		{
			heap_1.display_elements();
		}
		else if (choice == 4) // sprawdza ile jest obecnie elementow na stosie
		{
			cout << heap_1.count_elements() << endl;
		}
	} while (choice != 0);
	return 0;
}