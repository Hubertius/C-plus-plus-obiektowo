#include <iostream>
using namespace std;


/*
  Firma:
  pracownik (imie, nazwisko, rola, pensja, pracuj gdy firma dziala, przedstaw sie) 3 poziomy: tester, programista, manager
  przedstawienie sie, tester i programista chwala sie zarobkami
  jedna firma
  manager zamyka i otwiera firme

*/

class Manager;

class Firma
{
  private:
    static bool isopen;
  public:
    Firma();
    bool ifisopen();
    void close(Manager &obj);
    ~Firma();
};


class Pracownik
{
  protected:
    string name, surname, position;
    int pension;
  public:
    Pracownik(string pos, int pen, string n = "None", string sn = "None");
    void iswork(Firma &obj);
    string getposition();
    virtual void express();
    ~Pracownik();
};

class Tester : public Pracownik
{
  public:
    Tester(int pen, string n, string sn): Pracownik("Tester", pen, n, sn) {};
    void express() override;

};

class Programista : public Pracownik
{
  public:
    Programista(int pen, string n, string sn): Pracownik("Programista", pen, n, sn) {};
    void express() override;
};

class Manager : public Pracownik
{
  public:
    Manager(int pen, string n, string sn): Pracownik("Manager", pen, n, sn) {};
    void express() override;
    void close(Firma &obj);
};


