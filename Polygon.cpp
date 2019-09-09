#include "Polygon.h"
#include "PArray.h"
#include "Point.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

int Polygon::objectCount = 0;

Point constructorPoints[4];

Point* updateConstructorPoints(const Point& p1, const Point& p2,
	const Point& p3, const Point& p4 = Point(0, 0)) {
	constructorPoints[0] = p1;
	constructorPoints[1] = p2;
	constructorPoints[2] = p3;
	constructorPoints[3] = p4;
	return constructorPoints;
}


Rectangle::Rectangle(const int a, const int b, const int c, const int d)
	: Polygon(updateConstructorPoints(Point(a, b), Point(a, d), Point(c, d), Point(c, b)), 4) {}

double Rectangle::area() const {
	int length = pArr.get_point(3)->get_pos_x() - pArr.get_point(0)->get_pos_x();
	int width = pArr.get_point(3)->get_pos_y() - pArr.get_point(2)->get_pos_y();
	return std::abs((double)length * width);
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
	: Polygon(updateConstructorPoints(a, b, c), 3) {}

double Triangle::area() const {

	int x2x1 = pArr.get_point(1)->get_pos_x() - pArr.get_point(0)->get_pos_x(),
		y2y1 = pArr.get_point(1)->get_pos_y() - pArr.get_point(0)->get_pos_y(),
		x3x2 = pArr.get_point(2)->get_pos_x() - pArr.get_point(1)->get_pos_x(),
		y3y2 = pArr.get_point(2)->get_pos_y() - pArr.get_point(1)->get_pos_y(),
		x3x1 = pArr.get_point(2)->get_pos_x() - pArr.get_point(0)->get_pos_x(),
		y3y1 = pArr.get_point(2)->get_pos_y() - pArr.get_point(0)->get_pos_y();

	double a = std::sqrt(x2x1 * x2x1 + y2y1 * y2y1),
		b = std::sqrt(x3x2 * x3x2 + y3y2 * y3y2),
		c = std::sqrt(x3x1 * x3x1 + y3y1 * y3y1);

	double s = (a + b + c) / 2;

	return std::sqrt(s * (s - a) * (s - b) * (s - c));
}