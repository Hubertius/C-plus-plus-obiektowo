#include <iostream>
#include "Quiz.h"
using namespace std;

int main() 
{
	Pytanie p[5];
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		p[i].nr_pytania = i + 1;
		p[i].wczytaj();
		p[i].zadaj();
		sum += p[i].punkty;
	}
	cout << endl << "Ostateczna liczba punktow za caly quiz:  " << sum;
	return 0;
}