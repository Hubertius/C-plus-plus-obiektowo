#ifndef TOOLS_H_
#define TOOLS_H_
#include <iostream>

class Narzedzie
{
  public:
    Narzedzie() {}; // definicja wywoływana jako inline
    virtual void uzyj(int ileRazy) = 0; // metoda "czysto" wirtualna, nie trzeba jej więc definiować (tutaj)
    ~Narzedzie() {}; // definicja wywoływana jako inline
};

class Mlotek : public Narzedzie
{
  private:
    int m_licznik; // licznik
  public:
    Mlotek(int licznik = 0) { m_licznik = licznik; }; // definicja wywoływana jako inline
    void uzyj(int ileRazy) override; // ewidentne przesloniecie metody wirtualnej
    ~Mlotek() {}; // definicja wywoływana jako inline

};

#endif
