#include <iostream>
#include "firma.h"
using namespace std;


Firma::Firma()
{

}

bool Firma::isopen = true;

void Firma::close(Manager &obj)
{
  bool check = ifisopen();
  if( check == true )
  {

    isopen = false;
  }
}

Firma::~Firma()
{

}

bool Firma::ifisopen()
{
  return isopen;
}

Pracownik::Pracownik(string pos, int pen, string n, string sn)
{
  name = n;
  surname = sn;
  position = pos;
  pension = pen;
}

void Pracownik::iswork(Firma &obj)
{
  bool check = obj.ifisopen();
  if( check == true )
  {
    cout << "There is work in the company";
  }
  else
  {
    cout << "The isn't work in the company";
  }

}

void Pracownik::express()
{

}

string Pracownik::getposition()
{
  return position;
}

void Tester::express()
{
  cout << "Czesc, nazywam sie " << name << " " << surname << "." << endl;
  cout << "Jestem " << position << " i zarabiam " << pension << ".\n";
}


void Programista::express()
{
  cout << "Czesc, nazywam sie " << name << " " << surname << "." << endl;
  cout << "Jestem " << position << " i zarabiam " << pension << ".\n";
}

void Manager::express()
{
  cout << "Czesc, nazywam sie " << name << " " << surname << "." << endl;
  cout << "Jestem " << position << " i zarabiam " << pension << ".\n";
}



Pracownik::~Pracownik()
{

}
