#ifndef TEMPLATE_H_
#define TEMPLATE_H_

#include <iostream>
using namespace std;

template <typename T>
class Punkt // klasa bazowa
{
    protected:
        T m_x;
    public:
        Punkt(T x = 0);
        virtual ~Punkt();
        T getX();
        void setx(T x);
};

template <typename T>
class Punkt2D: public Punkt<T> // klasa pochodna
{
    protected:
        T m_y;
    public:
        Punkt2D(T x = 0, T y = 0): Punkt<T>(x) { this->m_y = y;}
        ~Punkt2D();
        T getY();
        void setY(T y);
        void setXY(T x, T y);
        Punkt2D operator+(Punkt2D point);
};








#endif