#include <iostream>
#include "firma.h"
using namespace std;

int main()
{
  Tester tester(3000, "Andrzej", "Zwolinski");
  Programista programista(5000, "Hubert", "Modrzejewski");
  Manager manager(4000, "Artur", "Swiderski");
  tester.express();
  programista.express();
  manager.express();
  Firma company;
  bool check = company.ifisopen();
  cout << "Czy firma jest otwarta czy zamknieta (0 - zamknieta, 1 - otwarta)?" << check << endl;
  company.close(manager);
  check = company.ifisopen();
  cout << "Czy firma jest otwarta czy zamknieta (0 - zamknieta, 1 - otwarta)?" << check << endl;

  return 0;
}
