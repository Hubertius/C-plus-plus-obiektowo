#include <iostream>
#include "przyjaciele.h"
using namespace std;

void sedzia(Punkt pkt, Prostokat prost)
{
	if ((pkt.x >= prost.x) && (pkt.x <= prost.x + prost.szerokosc) && (pkt.y >= prost.y) && (pkt.y <= prost.y + prost.wysokosc))
	{
		cout << "Punkt: " << pkt.nazwa << " nalezy do prostokata: " << prost.nazwa;
	}
	else
	{
		cout << "Punkt: " << pkt.nazwa << " NIE nalezy do prostokata: " << prost.nazwa;
	}
}

int main()
{
	Punkt point_1("A", 3, 17);
	Prostokat rectangle_1("Prostokat", 0, 0, 6, 4);
	
	sedzia(point_1, rectangle_1);
	return 0;
}

