#include <iostream>
#include "opona.h"

int Opona::Przebicie(int srednica)
{
    if( srednica > 10 )
    {
        m_przebita = 1;
    }
    return m_przebita;
}

int OponaBezdetkowa::Przebicie(int srednica) 
{
    if( srednica > 20 )
    {
        m_przebita = 1;
    }
    return m_przebita;
}