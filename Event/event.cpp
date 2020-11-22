#include <iostream>
#include "event.h"

using namespace std;
Event::Event(string n,int y, int mo, int d, int h, int mi)
{
	name = n;
	year = y;
	month = mo;
	day = d;
	hour = h;
	minutes = mi;
}

Event::~Event()
{

}

void Event::load()
{
	cout << "Name of the event: ";
	cin >> name;
	cout << "Year: ";
	cin >> year;
	cout << "Month: ";
	cin >> month;
	cout << "Day: ";
	cin >> day;
	cout << "Hour: ";
	cin >> hour;
	cout << "Minutes: ";
	cin >> minutes;
}

void Event::show()
{
	cout << "Name of the event: " << name << endl;
	cout << "Year: " << year << endl;
	cout << "Month: " << month << endl;
	cout << "Day: " << day << endl;
	cout << "Hour: " << hour << endl;
	cout << "Minutes: " << minutes << endl;
}