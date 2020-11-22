#include <iostream>
#include "punkt.h"
using namespace std;

int main()
{
    Punkt X(5, 3);
    Punkt Y(2, 1);
    Punkt Z;
    Z = X + Y;
    return 0;
}