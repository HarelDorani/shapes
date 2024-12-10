#pragma once

#include "Shape.h"
#include "Point.h"
#include <vector>

class Polygon : public Shape
{
public:

	// Constructor
	Polygon(std::string type, std::string name);

	// Destructor
	~Polygon();

	// Getters
	std::vector<Point> getPoints()const;

	// override methods if need (virtual + pure virtual)
	virtual double getArea()const = 0;    
	virtual double getPerimeter()const = 0;
	virtual void move(Point other) = 0; // add the Point coordinates to all the points coordinates in the shape

protected:
	std::vector<Point> _points;
};