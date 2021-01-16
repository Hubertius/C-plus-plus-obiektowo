#include <iostream>
#include "elektryka.h"

int main()
{
  Lampa pierwsza;
  std::cout << "Obiekt 'pierwsza' klasy Lampa" << std::endl;
  pierwsza.OdczytajMocLampy();
  pierwsza.UstawMocLampy(130);
  pierwsza.OdczytajMocLampy();
  pierwsza.UstawMocLampy(110);
  pierwsza.OdczytajMocLampy();


  Lampa druga(pierwsza);
  std::cout << "Druga Lampa (konstruktor kopiujacy z parametrem obiekt 'pierwsza' klasy Lampa ). " << std::endl;
  druga.OdczytajMocLampy();
  druga.UstawMocLampy(75);
  druga.OdczytajMocLampy();

  Lampa trzecia;
  std::cout << "Trzecia Lampa (operator przypisania z parametrem obiekt 'druga' klasy Lampa). " << std::endl;
  trzecia = druga;
  trzecia.OdczytajMocLampy();
  return 0;
}
