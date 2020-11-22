#include <iostream>
using namespace std;

class Prostokat;

class Punkt
{
	string nazwa;
	float x, y;
public:
	Punkt(string name = "brak", float x_cordinate = 0, float y_cordinate = 0);
	void wczytaj();

	friend void sedzia(Punkt pkt, Prostokat prost);
};

class Prostokat
{
	string nazwa;
	float x, y, szerokosc, wysokosc;
public:
	Prostokat(string name = "brak", float x_cordinate = 0, float y_cordinate = 0, float s = 1, float w = 1);
	void wczytaj();

	friend void sedzia(Punkt pkt, Prostokat prost);
};
