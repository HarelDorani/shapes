#include "Polygon.h"

Polygon::Polygon(std::string type, std::string name) : Shape(name, type)
{

}

Polygon::~Polygon()
{
	
}

std::vector<Point> Polygon::getPoints()const
{
	return this->_points;
}
