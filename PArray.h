#pragma once
#include "Point.h"
class PArray {
private:
	//Pointer to an array of Points
	Point* m_array_points;
	//Size of the Array
	int m_size;
	void resize(const int t_new_size);
public:
	//Default consturctor
	PArray();
	//Initializes Array with given t_size
	PArray(const Point t_array_points[], const int t_size);
	//Copys PArray to new PArray
	PArray(const PArray& t_points_array);
	//Adds element to last position
	void push_back(const Point &t_point);
	//Inserts element in given position
	void insert(const int t_position, const Point& t_point);
	//Removes element in give position
	void remove(const int t_position);
	
	Point *get_point(int t_pos);
	Point *get_point(int  t_pos) const;
	//Returns size
	int get_size() const;
	//Clears Array
	void clear();
	//Resizes Array
	
	//Destructor
	~PArray();
};