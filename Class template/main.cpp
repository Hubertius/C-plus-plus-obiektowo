#include <iostream>
#include "template.h"


int main()
{
    typedef Punkt2D<int> punkt2D_integer;
    typedef Punkt2D<double> punkt2D_double;

    punkt2D_integer first_point(5, 10);
    punkt2D_double  second_point(6.5, 12.5);

    cout << "For first point.\n";
    cout << "X: " << first_point.getX() << endl;
    cout << "Y: " << second_point.getY() << endl;

    cout << "For first point.\n";
    cout << "X: " << first_point.getX() << endl;
    cout << "Y: " << second_point.getY() << endl;
    return 0;
}