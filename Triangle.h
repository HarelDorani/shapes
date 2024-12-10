#include "Polygon.h"
#include <string>

class Triangle : public Polygon
{
public:

	// Constructor
	Triangle(Point a, Point b, Point c, std::string type, std::string name);

	// Destructor
	~Triangle();
	
	// override functions if need (virtual + pure virtual)
	virtual double getArea()const override;
	virtual double getPerimeter()const override;
	virtual void move(Point other)override;
	
	virtual void draw(const Canvas& canvas);
	virtual void clearDraw(const Canvas& canvas);
};