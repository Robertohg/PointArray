#include <iostream>
#include <iomanip> 
#include <vector>
#include <string>
#include "Point.h"
#include "PArray.h"
#include "Polygon.h"
#include <iostream>

int main()
{
	int j;
	Point a;
	Point d;
	a.set_pos_x(2);
	a.set_pos_y(2);
	d.set_pos_x(1);
	d.set_pos_y(1);
	PArray b;
	b.push_back(a);
	b.push_back(d);
	b.get_point(0);
	b.get_point(1);
	std::cout << "Hola" << std::endl;
	std::cin >> j;
	return 0;
}

