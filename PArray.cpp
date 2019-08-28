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
	memcpy(m_array_points, t_array_points, sizeof(int) * t_size);

}
PArray::PArray(const PArray& t_points_array) {
	this->m_size = t_points_array.m_size;
	this->m_array_points = (Point*)malloc(sizeof(Point) * m_size);
	memcpy(m_array_points, t_points_array.m_array_points, sizeof(int) * m_size);

}
PArray::~PArray() {
	free(this->m_array_points);
	delete m_array_points;
}