#include <iostream>
#include "elektryka.h"

Zarowka::Zarowka(int power )
{
  m_power = power;
}

void Zarowka::UstawMocZarowki(int power)
{
  m_power = power;
}
int Zarowka::OdczytajMocZarowki()
{
  return m_power;
}

Lampa::Lampa(const Lampa & innaLampa)
{
  one = innaLampa.one;
  two = innaLampa.two;
}
Lampa & Lampa::operator=(const Lampa & innaLampa)
{
  one = innaLampa.one;
  two = innaLampa.two;
  return *this;
}
void Lampa::UstawMocLampy(int power)
{
  if(power > 0 && power < 120 )
  {
    one.UstawMocZarowki(power);
    two.UstawMocZarowki(power);
  }
  else
  {
    std::cout << "Nie mozna bylo ustawic mocy zarowek ze wzglednu na to, ze nie moga miec mocy ponizej 0," << std::endl;
    std::cout << "jak i nie moga przekroczyc wartosci 120." << std::endl;
  }
}
void Lampa::OdczytajMocLampy()
{
  std::cout << "Moc pierwszej zarowki lampy: " << one.OdczytajMocZarowki() << std::endl;
  std::cout << "Moc drugiej zarowki lampy: " << two.OdczytajMocZarowki() << std::endl;
}




