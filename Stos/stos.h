#include <iostream>
#include <cstdlib>
using namespace std;

class Stos
{
private:
	int size, index;
	int* arr;
public:
	Stos(int); // Konstruktor, przy okazji alokuje pamięć na pierwsze 10 elementów typu integer na wskaźnik int * arr.
	~Stos(); // Destruktor, przy okazji zwolni pamięć na "wartości stosu" z int * arr.
	bool check_for_expand(); // Sprawdzanie, czy trzeba bedzie dokonac realokacji w przypadku, gdy pierwsze z brzegu wolne miejsce wykracza poza możliwy rozmiar.
	bool check_for_take_away(); // Sprawdzanie, czy mozna zrobic pop.
	int * expandHeap(); // Dokonuje realokacji pamięci na int * arr.
	void push(int); // Dodaje element na stos.
	int pop(); // Zabiera element ze stosu.
	void display_elements(); // Odczyta wszystkie wartosci ze stosu.
	int count_elements(); // Sprawdzi ile jest obecnie elementow na stosie.
};
