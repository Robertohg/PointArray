#pragma once
#include "Point.h"
class PArray {
private:
	//Pointer to an array of Points
	Point* m_array_points;
	//Size of the Array
	int m_size;

public:
	//Default consturctor
	PArray();
	//Initializes Array with given t_size
	PArray(const Point t_array_points[], const int t_size);
	//Copys PArray to new PArray
	PArray(const PArray& t_points_array);
	~PArray();
};