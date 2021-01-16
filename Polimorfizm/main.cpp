#include <iostream>
#include "polimorfizm.h"



int main()
{
  using std::cout;
  using std::endl;
  using std::cin;

  Kolo k1(1.5);
  Kwadrat square(1.2);

  Ksztalt * wsk = &k1;
  wsk->oblicz_pole();

  wsk = &square;
  wsk->oblicz_pole();

  obliczenia(wsk);

  return 0;
}
