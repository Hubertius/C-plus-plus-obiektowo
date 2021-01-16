#include <iostream>
#include"polimorfizm.h"

Kolo::Kolo(float r)
{
  m_r = r;
}

void Kolo::oblicz_pole()
{
  std::cout << "Pole kola: " << 3.14 * m_r * m_r << std::endl;
}


Kwadrat::Kwadrat(float x)
{
  m_x = x;
}

void Kwadrat::oblicz_pole()
{
  std::cout << "Pole kwadratu: " <<  m_x * m_x << std::endl;
}

void obliczenia(Ksztalt * pointer)
{
  pointer->oblicz_pole();
}


