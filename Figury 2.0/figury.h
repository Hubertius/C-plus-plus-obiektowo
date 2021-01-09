#include <iostream>
#include <cmath>
using namespace std;

#define M_PI 3.14;
class Figure
{
  protected:
    float width, height; // Szerokosc, wysokosc figury.
  public:
    Figure(float w, float h)
    {
      width = w;
      height = h;
    };
    virtual float circ() = 0;
    virtual float area() = 0;
    void set_width(float x = 0); // ustaw szerokosc
    float get_width(); // odczytaj szerokosc
    void set_height(float y = 0);
    float get_height();
};

class Circle:public Figure
{
  private:
    float r;
  public:
    Circle(float r = 0): Figure(r * 2, r * 2) {r = r;}; // r które jest wczytane w parametrze konstruktora i przypisujemy ją do private r.
    void set_r(float x = 0);
    float get_r();
    float circ() override // nadpisuje virtual dla tej klasy
    {
      float value = 2 * r * M_PI;
      return value;
    }
    float area() override // nadpisuje virtual dla tej klasy
    {
      float value =  pow(r, 2.0) * M_PI;
      return value;
    }
};

class Square:public Figure
{
  private:
    float side;
  public:
    Square(float x = 0): Figure(side, side) {side = x;}; // x które jest wczytane w parametrze konstruktora i przypisujemy ją do private side.
    void set_side(float x = 0);
    float get_side();
    float circ() override // nadpisuje virtual dla tej klasy
    {
      float value = 4 * side;
      return value;
    }
    float area() override // nadpisuje virtual dla tej klasy
    {
      float value = pow(side, 2.0);
      return value;
    }
};

class Ractangle: public Figure
{
  private:
    float side_first, side_second;
  public:
    Ractangle(float x = 0, float y = 0): Figure(side_first, side_second) {side_first = x; side_second = y;};// x które jest wczytane w parametrze konstruktora i przypisujemy ją do private side.
    void set_side(float x = 0);
    float get_side();
    float circ() override // nadpisuje virtual dla tej klasy
    {
      float value = 2 * side_first + 2 * side_second;
      return value;
    }
    float area() override // nadpisuje virtual dla tej klasy
    {
      float value = side_first * side_second;
      return value;
    }
};
