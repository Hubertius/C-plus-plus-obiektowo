#include <iostream>
using namespace std;

class Punkt
{
private:
    int x, y;
public:
    Punkt(int a = 1, int b = 1);
    void read_object();
    Punkt operator+ (Punkt& obj);
};