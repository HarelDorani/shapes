#include "Rectangle.h"

//////////////////////////////////////////////////////////////////////////////
// Canvas and Cimg cannot be used on Linux, 								//
// please make sure to leave it commented if you want test to run on GitLab //
// You can remove comments when you run your exercise locally on Windows .  //
//////////////////////////////////////////////////////////////////////////////

//a constructor
myShapes::Rectangle::Rectangle(Point a, double length, double width, std::string type, std::string name) : Polygon(type, name)
{
	Point b(a.getX() + length, a.getY());
	Point c(a.getX() + length, a.getY() +width);
	Point d(a.getX() , a.getY() + width);
	_points.push_back(a);
	_points.push_back(b);
	_points.push_back(c);
	_points.push_back(d);
}
//a destructor
myShapes::Rectangle::~Rectangle()
{
	
}

//a get to the area
double myShapes::Rectangle::getArea() const
{
	return  _points[0].distance(_points[1]) * _points[1].distance(_points[2]);
}

//a get to the parimeter
double myShapes::Rectangle::getPerimeter() const
{
	double dist = 0;
	//calculate the parimeter
	dist += _points[0].distance(_points[1]);
	dist += _points[1].distance(_points[2]);
	dist *= 2;
	return dist;
}

//a functioon to move the rectaangle
void myShapes::Rectangle::move(Point other)
{
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		_points[i] += other;
	}
}

void myShapes::Rectangle::draw(const Canvas& canvas)
{
	canvas.draw_rectangle(_points[0], _points[2]);
}

void myShapes::Rectangle::clearDraw(const Canvas& canvas)
{
	canvas.clear_rectangle(_points[0], _points[2]);
}


