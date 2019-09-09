#pragma once
#include "Point.h"
#include "PArray.h"
class Polygon {
protected:
	PArray pArr;
	static int objectCount;

public:
	Polygon(const Point points[], const int size) : pArr(points, size) { objectCount++; }
	Polygon(const PArray& passedArr) : pArr(passedArr) { objectCount++; }
	~Polygon() { objectCount--; }
	virtual double area() const = 0;
	static int getNumPolygons() { return objectCount; }
	int getNumSides() const { return pArr.get_size(); }
	const PArray* getPoints() const { return &pArr; }
};
class Rectangle : public Polygon {
public:
	
	Rectangle(const int a, const int b, const int c, const int d);
	virtual double area() const;
};

class Triangle : public Polygon {
public:
	Triangle(const Point& a, const Point& b, const Point& c);
	virtual double area() const;
};