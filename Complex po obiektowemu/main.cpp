#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
    Complex z1(1.0,-1.0);
    Complex z2(-1.0,1.0);
    z1.input_re();
    z1.input_im();
    z2.input_re();
    z2.input_im();
    z1.read_re_im();
    z2.read_re_im();
    Complex z3;
    int choice = choose_operation();
    if(choice == -1)
    {
        cout <<"Error! Program will shutdown immediately!" << endl;
        return 1;
    }
    else if(choice == 0)
    {
        cout << "Przechodzenie do zakonczenia programu natychmiast." << endl;
        return 0;
    }
    else if(choice == 1)
    {
        z3 = z1 + z2;
        z3.read_re_im();
    }
    else if(choice == 2)
    {
        z3 = z1 - z2;
        z3.read_re_im();
    }
    else if(choice == 3)
    {
        z3 = z1 * z2;
        z3.read_re_im();
    }
    else if(choice == 4)
    {
        z3 = z1 / z2;
        z3.read_re_im();
    }
    else if(choice == 5)
    {
        z1 += z2;
        z1.read_re_im();
    }
    else if(choice == 6)
    {
        z1 -= z2;
        z1.read_re_im();
    }
    else if(choice == 7)
    {
        z1 *= z2;
        z1.read_re_im();
    }
    else if(choice == 8)
    {
        z1 /= z2;
        z2.read_re_im();
    }
    else if(choice == 9)
    {
        bool check_for_equality = (z1 == z2);
        if(check_for_equality == true)
        {
            cout << "These two complex numbers are EQUAL." << endl;
        }
        else
        {
            cout << "These two complex numbers are NOT Equal." << endl;
        }
        cout << "z1 == z2: " << check_for_equality << endl;
    }
    else if(choice == 10)
    {
        bool check_for_inequality = (z1 != z2);
        if(check_for_inequality == true)
        {
            cout << "These two complex numbers are NOT equal(inquality == true)." << endl;
        }
        else
        {
            cout << "These two complex numbers are EQUAL(inquality == false)." << endl;
        }
        cout << "z1 != z2: " << check_for_inequality << endl;
    }
    else if(choice == 11)
    {
        int check;
        check = z3.negation(z1,z2);
        if(check == -1)
        {
            cout <<"Error! Program will shutdown immediatly!" << endl;
            return 1;
        }
        else if(check == 1)
        {
            z1.read_re_im();
        }
        else
        {
            z2.read_re_im();
        }
    }
    return 0;
}
