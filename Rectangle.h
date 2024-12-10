#pragma once
#include "Polygon.h"


namespace myShapes
{
	// Calling it MyRectangle becuase Rectangle is taken by global namespace.
	class Rectangle : public Polygon
	{
	public:

		// Constructor
		// There's a need only for the top left corner 
		Rectangle(Point a, double length, double width, std::string type, std::string name);

		// Destructor
		~Rectangle();

		// override methods if need (virtual + pure virtual)
		virtual double getArea()const override;
		virtual double getPerimeter()const override;
		virtual void move(Point other)override;
		
		virtual void draw(const Canvas& canvas);
		virtual void clearDraw(const Canvas& canvas);

	private:
	

	};
}