#include "PArray.h"
#include "Point.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
PArray::PArray() {
	this->m_size = 0;
	this->m_array_points = nullptr;
}
PArray::PArray(const Point t_array_points[], const int t_size) {

	this->m_size = t_size;
	this->m_array_points = new Point[t_size];
	for (int i = 0; i < t_size; i++) {
		this->m_array_points[i] = t_array_points[i];
	}

}
PArray::PArray(const PArray& t_points_array) {
	this->m_size = t_points_array.m_size;

	this->m_array_points = new Point[m_size];
	for (int i = 0; i < m_size; i++) {
		this->m_array_points[i] = t_points_array.m_array_points[i];
	}
}
PArray::~PArray() {
	free(this->m_array_points);
	delete m_array_points;
}
void PArray::resize(const int t_new_size) {

	Point *buff = new Point[t_new_size];
	int minSize = (t_new_size > this->m_size ? this->m_size : t_new_size);
	for (int i = 0; i < minSize; i++) {
		buff[i] = this->m_array_points[i];
	}
	delete[] this->m_array_points;
	this->m_size = t_new_size;
	this->m_array_points = buff;
	
}
void PArray::push_back(const Point& t_point) {
	resize(this->m_size + 1);
	m_array_points[this->m_size - 1] = t_point;

}
int PArray::get_size() const {
	return this->m_size;
}
void PArray::insert(const int t_position, const Point& t_point) {
	resize(this->m_size + 1);
	for (int i = this->m_size - 1; i > t_position; i--) {
		this->m_array_points[i] = this->m_array_points[i - 1];
	}
	this->m_array_points[t_position] = t_point;


}
void PArray::remove(const int t_position) {
	for (int i = t_position; i < this->m_size - 2; i++)
	{
		m_array_points[i] = m_array_points[i + 1];
	}
	resize(this->m_size - 1);
}
void PArray::clear() {
	resize(0);

}
Point *PArray::get_point(int t_pos)
{
	return t_pos >= 0 && t_pos < m_size ? m_array_points + t_pos : NULL;
}
Point* PArray::get_point(int t_pos) const
{
	return t_pos >= 0 && t_pos < m_size ? m_array_points + t_pos : NULL;
}