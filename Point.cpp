#include "Point.h"

Point::Point() {
	this->m_pos_x = 0;
	this->m_pos_y = 0;
}
Point::Point(int t_pos_x, int t_pos_y) {
	this->m_pos_x = t_pos_x;
	this->m_pos_y = t_pos_y;

}
void Point::set_pos_x(const int t_pos_x) {
	this->m_pos_x = t_pos_x;
}
void Point::set_pos_y(const int t_pos_y) {
	this->m_pos_y = t_pos_y;
}
const int Point::get_pos_x() {
	return this->m_pos_x;
}
const int Point::get_pos_y() {
	return this->m_pos_y;
}