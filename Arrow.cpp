#include "Arrow.h"

//////////////////////////////////////////////////////////////////////////////
// Canvas and Cimg cannot be used on Linux, 								//
// please make sure to leave it commented if you want test to run on GitLab //
// You can remove comments when you run your exercise locally on Windows .  //
//////////////////////////////////////////////////////////////////////////////

//a constructor
Arrow::Arrow(Point a, Point b, std::string type, std::string name) : Shape(name, type)
{
	//make sure the points are not the same
	if (a == b)
	{
		std::cout << "the points are the same" << std::endl;
		exit(1);
	}
	this->_points = new Point[2];
	_points[0] = a;
	_points[1] = b;

}

//distructor 
Arrow::~Arrow()
{
	delete[] _points;
}

//a get to the source point
Point Arrow::getSource()const
{
	return this->_points[0];
}

//a get to the dest point
Point Arrow::getDestination()const
{
	return this->_points[1];
}
//a get to the area
double Arrow::getArea()const
{
	return 0;
}

//a get to the perimeter
double Arrow::getPerimeter()const
{
	return _points[0].distance(_points[1]);
}

//finction to move the arrow
void Arrow::move(Point other)
{
	int i = 0;
	for (i = 0; i < 2; i++)
	{
		_points[i] += other;
	}
}

void Arrow::draw(const Canvas& canvas)
{
	canvas.draw_arrow(_points[0], _points[1]);
}
void Arrow::clearDraw(const Canvas& canvas)
{
	canvas.clear_arrow(_points[0], _points[1]);
}


