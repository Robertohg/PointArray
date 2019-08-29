#include "PArray.h"
#include "Point.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

PArray::PArray() {
	this->m_size = 0;
	this->m_array_points = nullptr;
}
PArray::PArray(const Point t_array_points[], const int t_size) {
	this->m_size = t_size;
	this->m_array_points = (Point*)malloc(sizeof(Point) * t_size);
	memcpy(m_array_points, t_array_points, sizeof(Point) * t_size);

}
PArray::PArray(const PArray& t_points_array) {
	this->m_size = t_points_array.m_size;
	this->m_array_points = (Point*)malloc(sizeof(Point) * m_size);
	memcpy(m_array_points, t_points_array.m_array_points, sizeof(Point) * m_size);

}
PArray::~PArray() {
	free(this->m_array_points);
	delete m_array_points;
}
void PArray::resize(const int t_new_size) {
	if (this->m_array_points != nullptr) {
		Point* Arr = new Point[t_new_size];
		Arr = (Point*)malloc(sizeof(Point) * t_new_size);
		memcpy(Arr, this->m_array_points, sizeof(Point) * this->m_size);
		this->m_array_points = Arr;
		this->m_size = t_new_size;
		delete []Arr;
	}
}
void PArray::push_back(const Point& t_point) {
	if (this->m_array_points == nullptr)
	{
		this->m_array_points = (Point*)malloc(sizeof(Point) * 1);
		m_array_points[0] = t_point;
	}
	else {
		this->resize(this->m_size++);
		
		this->m_array_points[this->m_size] = t_point;
		this->m_size += 1;
	}
}
int PArray::get_size() const {
	return this->m_size;
}
void PArray::insert(const int t_position, const Point& t_point) {
	
	if (this->m_array_points == nullptr)
	{
		int poss = t_position + 1;
		this->m_array_points = (Point*)malloc(sizeof(Point) * poss);
		this->m_array_points[t_position] = t_point;
	}
	else {
		int poss = this->m_size++;
		this->resize(poss);
		for (int iter = this->m_size--; t_position <= iter; iter--) {
			this->m_array_points[iter] = this->m_array_points[iter--];
		}
		this->m_array_points[t_position] = t_point;
	}
}
void PArray::remove(const int t_position) {
	for (int iter = t_position; t_position < this->m_size; iter++) {
		this->m_array_points[iter] = this->m_array_points[iter++];
	}
	this->resize(this->m_size--);
}
void PArray::clear() {
	while (this->m_array_points!= nullptr)
	{
		this->remove(this->m_size--);
	}

}