#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "pip.h"
using namespace std;

Punkt::Punkt(string n, float a, float b)
{
  nazwa = n;
  x = a;
  y = b;
}

void Punkt::wyswietl()
{
  cout << nazwa << "("<<x<<", "<<y<<")" << endl;
}

Kolo::Kolo(string nk, string np, float a, float b, float pr) : Punkt(np, a, b)
{
  nazwa = nk;
  r = pr;
}

void Kolo::wyswietl()
{
  cout << "Kolo o nazwie: " << nazwa << endl;
  cout << "Srodek kola: ";
  Punkt::wyswietl();
  cout << "Promien: " << r << endl;
  cout << "Pole kola: " << r * r * M_PI << endl;
}

