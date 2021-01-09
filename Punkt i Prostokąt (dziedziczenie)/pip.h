#include <iostream>
using namespace std;

class Punkt
{
  private:
    float x, y;
    string nazwa;
  public:
    Punkt(string n = "S", float a = 0, float b = 0);
    void wyswietl();

};

class Kolo :public Punkt // dziedziczenie public nic nie zmienia w kwestii hermeryzacji danych z klasy podstawowej
{
  private:
    float r;
    string nazwa;  // przesloniecie atrybutu nazwa z klasy podstawowej w tejże klasie
  public:
    Kolo(string nk = "Kolko", string np = "S", float a = 0, float b = 0, float pr = 1);
    void wyswietl();

};
