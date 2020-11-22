#include <iostream>
#include "event.h"

using namespace std;

int main()
{
	Event new_event("Hipsteria", 2012, 12, 8, 4, 30);

	new_event.show();
	return 0;
}