#include <iostream>
#include "punkt.h"
using namespace std;

Punkt::Punkt(int a, int b)
{
    x = a;
    y = b;

}
void Punkt::read_object()
{
    cout << "X: " << x << " " << "Y: " << y << endl;
}
Punkt  Punkt::operator+ (Punkt& obj) 
{
    Punkt wynik;
    wynik.x = x + obj.x;
    wynik.y = y + obj.y;
    return wynik;
}