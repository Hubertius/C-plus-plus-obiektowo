#include <iostream>
using namespace std;


class Complex
{
    private:
        double re, im;
    public:
        Complex(double real=1.0,double imagine=1.0);
        //Complex(double real=1.0,double imagine=1.0) re(real), im(imagine) {}
        int input();
        void read();
        Complex operator+ (const Complex &obj_second);
        Complex operator- (const Complex &obj_second);
        Complex operator* (const Complex  &obj_second);
        Complex operator/ (const Complex & obj_second);
        bool operator==(const Complex & obj_second);
        bool operator!=(const Complex &obj_second);
        int negation(Complex &first, Complex &second); //Zapytac, czy mozna przeladowac operator negacji z uzyciem "operator~".
        ~Complex();
};

int choose_operation();