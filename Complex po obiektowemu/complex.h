#include <iostream>
using namespace std;


class Complex
{
    private:
        double re, im;
    public:
        Complex(double real=1.0,double imagine=1.0);
        int input();
        void read();
        Complex operator+ (const Complex &obj_second);
        Complex operator- (const Complex &obj_second);
        Complex operator* (const Complex  &obj_second);
        Complex operator/ (const Complex & obj_second);
        bool operator==(const Complex & obj_second);
        bool operator!=(const Complex &obj_second);
        int negation(Complex &first, Complex &second);
};

int choose_operation();