#include <iostream>
#include "punkt.h"
using namespace std;

int main()
{
    Punkt X(5,3);
    Punkt Y(2,1);
    Punkt D;
    D = X + Y;
    D.read_object();
    Punkt O;
    O = X - Y;
    O.read_object();
    return 0;
}