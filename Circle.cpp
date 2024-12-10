#include "Circle.h"


//////////////////////////////////////////////////////////////////////////////
// Canvas and Cimg cannot be used on Linux, 								//
// please make sure to leave it commented if you want test to run on GitLab //
// You can remove comments when you run your exercise locally on Windows .  //
//////////////////////////////////////////////////////////////////////////////

void Circle::draw(const Canvas& canvas)
{
	canvas.draw_circle(getCenter(), getRadius());
}

void Circle::clearDraw(const Canvas& canvas)
{
	canvas.clear_circle(getCenter(), getRadius());
}

//a constructor
Circle::Circle(Point center, double radius, std::string type, std::string name) : Shape(name, type)
{
	//make sure the radius is  not 0
	if (radius < 0)
	{
		std::cout << "negtive radius" << std::endl;
		exit(1);
	}
	this->_center = center;
	this->_radius = radius;
	
}

//destructor
Circle::~Circle()
{
	
}

//a get to the center
Point Circle::getCenter()const
{
	return this->_center;
}
//a get to the radius
double Circle::getRadius()const
{
	return this->_radius;
}
//a fet to the area
double Circle::getArea() const
{
	double area = 0;
	area = _radius * _radius;
	area *= PI;
	return area;
}

//a get to  the parimeter
double Circle::getPerimeter() const
{
	double p = 0;
	p = _radius * 2;
	p *= PI;
	return p;
}
// a function to move the circle
void Circle::move(Point other)
{
	this->_center += other;
}
