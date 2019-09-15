#include "Polygon.h"
#include "PArray.h"
#include "Point.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

int Polygon::objectCount = 0;

Point constructorPoints[5];

Point* updateConstructorPoints(const Point& p1, const Point& p2 = Point(0, 0),
	const Point& p3 = Point(0, 0), const Point& p4 = Point(0, 0), const Point& p5 = Point(0, 0)) {
	constructorPoints[0] = p1;
	constructorPoints[1] = p2;
	constructorPoints[2] = p3;
	constructorPoints[3] = p4;
	constructorPoints[4] = p5;
	return constructorPoints;
}


Rectangle::Rectangle(const int a, const int b, const int c, const int d)
	: Polygon(updateConstructorPoints(Point(a, b), Point(a, d), Point(c, d), Point(c, b)), 4) {}

double Rectangle::area() const {
	int length = pArr.get_point(3)->get_pos_x() - pArr.get_point(0)->get_pos_x();
	int width = pArr.get_point(3)->get_pos_y() - pArr.get_point(2)->get_pos_y();
	return std::abs((double)length * width);
}

double Rectangle::perimetro() const {
	int length = pArr.get_point(3)->get_pos_x() - pArr.get_point(0)->get_pos_x();
	int width = pArr.get_point(3)->get_pos_y() - pArr.get_point(2)->get_pos_y();
	return std::abs(2 * length + 2 * width);
}

Pentagon::Pentagon(const int a, const int b, const int c, const int d) 
	: Polygon(updateConstructorPoints(Point(a, b), Point(a, d), Point(c, d), Point(c, b)), 4) {}

double Pentagon::area() const {

	// decagono.com/pentagono-area.php
	int X = pArr.get_point(1)->get_pos_x - pArr.get_point(0)->get_pos_x;
	int Y = pArr.get_point(1)->get_pos_y - pArr.get_point(0)->get_pos_y;
	double distancia = std::sqrt(std::pow(X, 2) - std::pow(Y, 2));

	return 1.720477 * std::pow(distancia, 2);

}
double Pentagon::perimetro()const {
	int X = pArr.get_point(1)->get_pos_x - pArr.get_point(0)->get_pos_x;
	int Y = pArr.get_point(1)->get_pos_y - pArr.get_point(0)->get_pos_y;
	double distancia = std::sqrt(std::pow(X, 2) - std::pow(Y, 2));
	return distancia * 5;

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

double Triangle::perimetro() const {
	int x2x1 = pArr.get_point(1)->get_pos_x() - pArr.get_point(0)->get_pos_x(),
		y2y1 = pArr.get_point(1)->get_pos_y() - pArr.get_point(0)->get_pos_y(),
		x3x2 = pArr.get_point(2)->get_pos_x() - pArr.get_point(1)->get_pos_x(),
		y3y2 = pArr.get_point(2)->get_pos_y() - pArr.get_point(1)->get_pos_y(),
		x3x1 = pArr.get_point(2)->get_pos_x() - pArr.get_point(0)->get_pos_x(),
		y3y1 = pArr.get_point(2)->get_pos_y() - pArr.get_point(0)->get_pos_y();
	
	double dis1 = std::sqrt(std::pow(x2x1, 2) - std::pow(y2y1, 2)),
		   dis2 = std::sqrt(std::pow(x3x2, 2) - std::pow(y3y2, 2)),
		   dis3 = std::sqrt(std::pow(x3x1, 2) - std::pow(y3y1, 2));
	return dis1 + dis2 + dis3;
}
Isoceles::Isoceles(const Point& a, const Point& b, const Point& c)
	: Polygon(updateConstructorPoints(a, b, c), 3) {}

double Isoceles::area() const {
	int x2x1 = pArr.get_point(1)->get_pos_x() - pArr.get_point(0)->get_pos_x(),
		y2y1 = pArr.get_point(1)->get_pos_y() - pArr.get_point(0)->get_pos_y(),
		x3x2 = pArr.get_point(2)->get_pos_x() - pArr.get_point(1)->get_pos_x(),
		y3y2 = pArr.get_point(2)->get_pos_y() - pArr.get_point(1)->get_pos_y();
	double dis1 = std::sqrt(std::pow(x2x1, 2) - std::pow(y2y1, 2)),
		   dis2 = std::sqrt(std::pow(x3x2, 2) - std::pow(y3y2, 2));
	double a = dis1 / 2;
	double hegith = std::sqrt(std::pow(dis2, 2) - std::pow(a, 2));
	return (dis1 * hegith) / 2;
}
double Isoceles::perimetro() const {
	int x2x1 = pArr.get_point(1)->get_pos_x() - pArr.get_point(0)->get_pos_x(),
		y2y1 = pArr.get_point(1)->get_pos_y() - pArr.get_point(0)->get_pos_y(),
		x3x2 = pArr.get_point(2)->get_pos_x() - pArr.get_point(1)->get_pos_x(),
		y3y2 = pArr.get_point(2)->get_pos_y() - pArr.get_point(1)->get_pos_y(),
		x3x1 = pArr.get_point(2)->get_pos_x() - pArr.get_point(0)->get_pos_x(),
		y3y1 = pArr.get_point(2)->get_pos_y() - pArr.get_point(0)->get_pos_y();

	double dis1 = std::sqrt(std::pow(x2x1, 2) - std::pow(y2y1, 2)),
		dis2 = std::sqrt(std::pow(x3x2, 2) - std::pow(y3y2, 2)),
		dis3 = std::sqrt(std::pow(x3x1, 2) - std::pow(y3y1, 2));
	return dis1 + dis2 + dis3;
}

Equilatero::Equilatero(const Point& a, const Point& b, const Point& c)
	: Polygon(updateConstructorPoints(a, b, c), 3) {}

double Equilatero::area() const {
	int x2x1 = pArr.get_point(1)->get_pos_x() - pArr.get_point(0)->get_pos_x(),
		y2y1 = pArr.get_point(1)->get_pos_y() - pArr.get_point(0)->get_pos_y();
	double dis1 = std::sqrt(std::pow(x2x1, 2) - std::pow(y2y1, 2));

	return std::pow(3,0.5) / 4 * std::pow(dis1, 2);
}


double Equilatero::perimetro() const {
	int x2x1 = pArr.get_point(1)->get_pos_x() - pArr.get_point(0)->get_pos_x(),
		y2y1 = pArr.get_point(1)->get_pos_y() - pArr.get_point(0)->get_pos_y(),
		x3x2 = pArr.get_point(2)->get_pos_x() - pArr.get_point(1)->get_pos_x(),
		y3y2 = pArr.get_point(2)->get_pos_y() - pArr.get_point(1)->get_pos_y(),
		x3x1 = pArr.get_point(2)->get_pos_x() - pArr.get_point(0)->get_pos_x(),
		y3y1 = pArr.get_point(2)->get_pos_y() - pArr.get_point(0)->get_pos_y();

	double dis1 = std::sqrt(std::pow(x2x1, 2) - std::pow(y2y1, 2)),
		dis2 = std::sqrt(std::pow(x3x2, 2) - std::pow(y3y2, 2)),
		dis3 = std::sqrt(std::pow(x3x1, 2) - std::pow(y3y1, 2));
	return dis1 + dis2 + dis3;
}

Circulo::Circulo(const Point& a, const Point& b)
	: Polygon(updateConstructorPoints(a, b), 2) {}

double Circulo::area() const {
	int x2x1 = pArr.get_point(1)->get_pos_x() - pArr.get_point(0)->get_pos_x(),
		y2y1 = pArr.get_point(1)->get_pos_y() - pArr.get_point(0)->get_pos_y();
	double radio = std::sqrt(std::pow(x2x1, 2) - std::pow(y2y1, 2));

	return 3.14 * std::pow(radio, 2);
}

double Circulo::perimetro() const {
	int x2x1 = pArr.get_point(1)->get_pos_x() - pArr.get_point(0)->get_pos_x(),
		y2y1 = pArr.get_point(1)->get_pos_y() - pArr.get_point(0)->get_pos_y();
	double radio = std::sqrt(std::pow(x2x1, 2) - std::pow(y2y1, 2));
	return 3.14 * radio * 2;
}
