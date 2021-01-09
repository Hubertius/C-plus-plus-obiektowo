#include <iostream>
using namespace std;

class Real
{
    protected:
      double re;
    public:
      Real();
      int input_re();
      void read_re();

};
class Complex :public Real
{
    private:
        double im;
    public:
        Complex(double real=1.0,double imagine=1.0);
        //Complex(double real=1.0,double imagine=1.0) re(real), im(imagine) {}
        int input_im();
        void read_re_im();
        Complex operator+ (const Complex &obj_second);
        Complex operator- (const Complex &obj_second);
        Complex operator* (const Complex  &obj_second);
        Complex operator/ (const Complex & obj_second);
        Complex & operator+= (const Complex &obj_second);
        Complex & operator-= (const Complex &obj_second);
        Complex & operator*= (const Complex  &obj_second);
        Complex & operator/= (const Complex & obj_second);
        bool operator==(const Complex & obj_second);
        bool operator!=(const Complex &obj_second);
        int negation(Complex &first, Complex &second); //Zapytac, czy mozna przeladowac operator negacji z uzyciem "operator~".
        ~Complex();
};

int choose_operation();
