#pragma once
#include "Shape.h"

class Arrow : public Shape
{
public:

	// Constructor
	Arrow(Point a, Point b, std::string type, std::string name);

	// Destructor
	~Arrow();

	// Getters
	Point getSource()const;
	Point getDestination()const;

	
	
	virtual double getArea()const override;
	virtual double getPerimeter()const override;
	virtual void move(Point other)override;
	
	
	 virtual void draw(const Canvas& canvas);
	 virtual void clearDraw(const Canvas& canvas);


private:
	Point* _points;
};