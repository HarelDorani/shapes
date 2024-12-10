#include "Point.h"
//deffault constructor
Point::Point()
{
	this->_x = 0;
	this->_y = 0;
}
//constructor
Point::Point(double x, double y)
{
	this->_x = x;
	this->_y = y;
}
//destructor
Point::~Point()
{
}

//the operator + to add points
Point Point::operator+(const Point& other) const
{
	Point add;
	add._x = this->_x + other.getX();
	add._y = this->_y + other.getY();
	return add;
}

//the operator += to add two piunts
Point& Point::operator+=(const Point& other)
{
	this->_x += other.getX();
	this->_y += other.getY();
	return *this;
}

//a get to the x
double Point::getX() const
{
	return this->_x;
}

// a get to the y
double Point::getY() const
{
	return this->_y;
}

//a function to calculate distance
double Point::distance(const Point& other)const
{

	double dx = this->_x - other.getX();//dx
	double dy = this->_y - other.getY();//dy

	return sqrt(dx * dx + dy * dy);//sdding it all
}

//opetator ==
bool Point::operator==(Point& other)
{
	bool to_return;
	to_return = (this->getX() == other.getX()) && (this->getY() == other.getY());
	return to_return;
	
}
