#pragma once

#include "Shape.h"
#include "Point.h"

#define PI 3.14

class Circle : public Shape
{
public:

	// Constructor
	Circle(Point center, double radius, std::string type, std::string name);

	// Destructor
	~Circle();

	// Getters
	Point getCenter()const;
	double getRadius()const;
	
	// override methods if need (virtual + pure virtual)

	virtual double getArea()const override;
	virtual double getPerimeter()const override;
	virtual void move(Point other)override;
	
	virtual void draw(const Canvas& canvas)override;
	virtual void clearDraw(const Canvas& canvas)override;

private:

	Point _center; 
	double _radius;
};