#include <iostream>
#include "przyjaciele.h"
using namespace std;

Punkt::Punkt(string n, float xx, float yy)
{
	nazwa = n;
	x = xx;
	y = yy;
}

void Punkt::wczytaj()
{
	cout << "Nazwa punktu: ";
	cin >> nazwa;
	cout << "Podaj x: ";
	cin >> x;
	cout << "Poday y: ";
	cin >> y;
}

Prostokat::Prostokat(string name, float x_cordinate, float y_cordinate, float s, float w)
{
	nazwa = name;
	x = x_cordinate;
	y = y_cordinate;
	szerokosc = s;
	wysokosc = w;
}

void Prostokat::wczytaj()
{
	cout << "Podaj x lewego dolngo naroznika: ";
	cin >> x;
	cout << "Podaj y lewego dolnego naroznika: ";
	cin >> y;
	cout << "Podaj szerokosc: ";
	cin >> szerokosc;
	cout << "Podaj wysokosc: ";
	cin >> wysokosc;
}