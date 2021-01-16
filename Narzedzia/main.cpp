#include "tools.h"

int main()
{
  int value;
  bool check;
  std::cout << "Podaj jaka wartosc startowa chcesz miec dla licznika: ";
  do
  {
    check = (std::cin >> value);
    if( check == false )
    {
      std::cout << "Blad! Najprawdopodobniej w ogole nie podales liczby cyfry! Jak mogles!  :(" << std::endl;
      std::cout << "Sprobuj jeszcze raz! Teraz na pewno Ci sie uda. :D" << std::endl;
      std::cout << "Wartosc: ";
      std::cin.clear();
      while( std::cin.get() != '\n' )
      {
        continue;
      }
    }
    else if( value < 0 )
    {
      std::cout << "Blad! Najprawdopodobniej podales liczbe lub cyfre ponizej zera! Jak mogles!  :(" << std::endl;
      std::cout << "Sprobuj jeszcze raz! Teraz na pewno Ci sie uda. :D" << std::endl;
      std::cout << "Wartosc: ";
    }
  } while( check == false || value < 0 );
  Mlotek my_hammer(value);
  my_hammer.uzyj(10);

  Narzedzie * pointer = &my_hammer; // pointer  klasy "bazowej abstrakcyjnej" (narzedzie) wskazuje na obiekt klasy dziedziczacej (mlotek)
  pointer->uzyj(5);

  return 0;
}
