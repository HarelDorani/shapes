#include "Triangle.h"

//a constractor
Triangle::Triangle(Point a, Point b, Point c, std::string type, std::string name) : Polygon(type, name)
{
	_points.push_back(a);
	_points.push_back(b);
	_points.push_back(c);

}

//a distructor
Triangle::~Triangle()
{
}

// a function to get the area
double Triangle::getArea() const
{
	//using the haron formula
	double s = this->getPerimeter() / 2;//half of the perimeter 
	double area = s;
	area *= s - _points[0].distance(_points[1]);
	area *= s - _points[1].distance(_points[2]);
	area *= s - _points[2].distance(_points[0]);
	return sqrt(area);

}

//a function to get the parimeter
double Triangle::getPerimeter() const
{
	return _points[0].distance(_points[1]) + _points[1].distance(_points[2]) + _points[0].distance(_points[2]);
}

//a functio  to move the triangle
void Triangle::move(Point other)
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		_points[i] += other;
	}
}

 void Triangle::draw(const Canvas& canvas)
{
canvas.draw_triangle(_points[0], _points[1], _points[2]);
}

void Triangle::clearDraw(const Canvas& canvas)
{
	canvas.clear_triangle(_points[0], _points[1], _points[2]);
}
