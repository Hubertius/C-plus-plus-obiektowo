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
    cout << "X: " << x << " " << "Y: " << y <<endl;
}
Punkt Punkt :: operator+ (Punkt &obj)
{
    Punkt Wynik;
    Wynik.x = x + obj.x;
    Wynik.y = y + obj.y;
    return Wynik;
}
Punkt Punkt :: operator- (Punkt &obj)
{
    Punkt Wynik;
    Wynik.x = x - obj.x;
    Wynik.y = y - obj.y;
    return Wynik;
}