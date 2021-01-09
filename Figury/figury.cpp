#include <iostream>
#include <figury.h>
#include <cmath>
using namespace std;

const double PI  =3.141592653589793238463;

Kolo::Kolo()
{
    kolo_r = 1.0;
}
int Kolo::input_kolo()
{
  cout << "Podaj wartosc dla promienia kola: ";
  double r;
  if(!(cin>>r))
  {
      cin.clear();
      cin.sync();
      cout << "ERORR! PROGRAM will shutdown now!";
      return 1;
  }
  kolo_r = r;
  return 0;
}
void Kolo::read_kolo()
{
    cout << "Wartosc PROMIENIA: " << kolo_r << "." << endl;
    cout << "Obwod KOLA: " << PI * 2 * kolo_r << endl;
    cout << "Pole kola: " << pow(kolo_r, 2.0) * PI << endl;
}
Kolo::~Kolo()
{

}
