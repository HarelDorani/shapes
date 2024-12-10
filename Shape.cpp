#include "Shape.h"

void Shape::printDetails()
{
	std::cout << this->getName() << std::endl;
	std::cout << this->getType() << std::endl;
}

Shape::Shape(std::string name, std::string type)
{
	this->_name = name;
	this->_type = type;
}

Shape::~Shape()
{
}

std::string Shape::getType()const
{
	return this->_type;
}

std::string Shape::getName()const
{
	return this->_name;
}
