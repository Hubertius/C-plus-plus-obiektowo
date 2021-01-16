#include "tools.h"


void Mlotek::uzyj(int ileRazy)
{
  if( m_licznik >= 10 )
  {
    std::cout << "Licznik jest wiekszy badz rowny 10. Jego wartosc: " << m_licznik << std::endl;
  }
  for(int i = 0; i < ileRazy; i++)
  {
    if( m_licznik < 10 )
    {
      std::cout << "Lup!" << std::endl;
    }
    else
    {
      std::cout << "Zepsuty :(" << std::endl;
    }
    m_licznik++;
  }
}

