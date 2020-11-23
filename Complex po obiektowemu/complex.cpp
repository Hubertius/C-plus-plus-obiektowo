#include <iostream>
#include <cmath>
using namespace std;
#include "complex.h"

Complex::Complex(double real,double imagine)
{
    re = real;
    im = imagine;
}
int Complex::input()
{
    cout << "Podaj dane do pierwszego obiektu." << endl;
    double re_x;
    cout << "X: ";
    if(!(cin >> re_x))
    {
        cin.clear();
        cin.sync();
        cout << "Error! Program will shutdown immediatly!" << endl;
        return 1;
    }
    cout << "Y:  ";
    double im_y;
    if(!(cin >> im_y))
    {
        cin.clear();
        cin.sync();
        cout << "Error! Program will shutdown immediatly!" << endl;
        return 1;
    }
    re = re_x;
    im = im_y;
    return 0;
}
void Complex::read()
{
cout << "Wartosci rzeczywiste i wyobrazone liczby zespolonej sa ponizej." << endl;
   if(im >= 0 )
   {
       cout << re << "+" <<im << "i" << endl;
   }
   else
   {
       cout << re << im << "i" << endl;
   }
   
}
Complex Complex :: operator+ (const Complex &obj_second)
{
    cout << "TUTAJ!";
    Complex result;
    result.re = re + obj_second.re;
    result.im = im + obj_second.im;
    return result;
}
Complex Complex :: operator- (const Complex &obj_second)
{
    Complex result;
    result.re = re - obj_second.re;
    result.im = im - obj_second.im;
    return result;
}
Complex Complex :: operator* (const Complex &obj_second)
{
    Complex result;
    double reality_part = re * obj_second.re;
    double imaginary_part = (re * obj_second.im) + (im * obj_second.re) + (im * obj_second.im) * (-1);
    result.re = reality_part;
    result.im = imaginary_part;
    return result;
}
Complex Complex :: operator/ (const Complex &obj_second)
{
    Complex result;
    double divise = pow(obj_second.re,2.0) + pow(obj_second.im,2.0);
    double reality_part = re * obj_second.re;
    double imaginary_part = (re * obj_second.im) + (im * obj_second.re) + (im * obj_second.im);
    result.re = reality_part/divise;
    result.im = imaginary_part/divise;
    return result;
}
bool Complex:: operator== (const Complex & obj_second)
{
    bool score;
    if(re == obj_second.re && im == obj_second.im)
    {
        return true;
    }
    return false;
}
bool Complex:: operator!= (const Complex &obj_second)
{
     bool score;
    if(re != obj_second.re || im != obj_second.im)
    {
        return true;
    }
    return false;
}
int Complex :: negation(Complex &first, Complex &second)
{
    cout << "Ktora liczbe zespolona chcesz zanegowac? Pierwsza czy druga? (1/2)";
    int choose_first_or_second;
    if(!(cin >> choose_first_or_second))
    {
        cin.clear();
        cin.sync();
        return -1;
    }
    if(choose_first_or_second<1 || choose_first_or_second >2)
    {
        cin.clear();
        cin.sync();
        return -1;
    }
    if(choose_first_or_second == 1)
    {
        first.re *= -1;
        first.im *= -1;
    }
    if(choose_first_or_second  == 2)
    {
        second.re *= -1;
        second.im *= -1;
    }
    return choose_first_or_second;
}
Complex::~Complex()
{
    
}




int choose_operation()
{
    cout << "Wybierz operacje na liczbach kompleksowych:"<< endl;
    cout << "0 - zakoncz programu." << endl;
    cout << "1 - dodaj dwie liczby zespolone tworzac tym samym trzecia." << endl;
    cout << "2 - odejmij dwie liczby zespolone tworzac tym samym trzecia." << endl;
    cout << "3 - pomnoz dwie liczby zespolone tworzac tym samym trzecia." << endl;
    cout << "4 - podziel dwie liczby zespolone tworzac tym samym trzecia." << endl;
    cout << "5 - dodaj druga liczbe zespolona do pierwszej." << endl;
    cout << "6 - odejmij druga liczbe zespolona od drugiej." << endl;
    cout << "7 - pomnoz pierwsza liczbe zespolona przez druga." << endl;
    cout << "8 - podziel pierwsza liczbe zespolona przez druga." << endl;
    cout << "9 - sprawdzenie czy pierwsza liczba zespolona jest rowna drugiej (true/false)." << endl;
    cout << "10 - sprawdzenie czy pierwsza liczba zespolona jest rozna od drugiej (true/false)." << endl;
    cout << "11 - Zaneguj liczbe zespolona." << endl;
    cout << "WYBOR: ";
    int choice;
    if(!(cin>>choice))
    {
        cin.clear();
        cin.sync();
        return -1;
    }
    return choice;
}
