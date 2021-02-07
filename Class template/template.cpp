#include "template.h"

template <typename T>
Punkt<T>::Punkt(T x)
{
    this->x;
}

template <typename T>
Punkt<T>::~Punkt()
{

}

template <typename T>
T Punkt<T>::getX()
{
    return this->x;
}

template <typename T>
void Punkt<T>::setX(T x)
{
     cout << "ja jestem z punkt" << endl;     
    this->x = x;
}

template <typename T>
Punkt2D<T>::~Punkt2D()
{

}

template <typename T>
T Punkt2D<T>::getY()
{
    return this->m_y;
}


template <typename T>
void Punkt2D<T>::setY(T y)
{
    this->m_y = y;
}

template <typename T>
void Punkt2D<T>::setXY(T x, T y)
{
    setX(x);
    setY(y);
}

template <typename T>
Punkt2D<T> Punkt2D<T>::operator+(Punkt2D<T> point)
{
    Punkt2D<T> temp;
    temp.m_x = this->getX() + point.getX();
    temp.m_y = this->getY() + point.getY();
}
