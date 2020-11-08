#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>
#include <string>
#include "Quiz.h"
using namespace std;

void Pytanie::wczytaj()
{
	fstream plik;
	plik.open("quiz.txt", ios::in);

	int nr_linii = (nr_pytania - 1) * 6 + 1;
	int aktualna_linia = 1;
	while (getline(plik, tresc))
	{
		if (aktualna_linia == nr_linii )
		{
			pytanie = tresc;
		}
		else if (aktualna_linia == nr_linii + 1)
		{
			a = tresc;
		}
		else if (aktualna_linia == nr_linii + 2)
		{
			b = tresc;
		}
		else if (aktualna_linia == nr_linii + 3)
		{
			c = tresc;
		}
		else if (aktualna_linia == nr_linii + 4)
		{
			d = tresc;
		}
		else if (aktualna_linia == nr_linii + 5)
		{
			poprawna = tresc;
		}
		aktualna_linia++;
	}
}
void Pytanie::zadaj()
{
	cout << pytanie << endl;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << "Jaka jest twoja odpowiedz? ";
	cin >> odpowiedz;
	if (odpowiedz == poprawna)
	{
		punkty = 1;
	}
	else
	{
		punkty = 0;
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}