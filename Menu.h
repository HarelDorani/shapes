#pragma once
#include "Shape.h"
#include "Canvas.h"
#include "Arrow.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <vector>



class Menu
{
public:

	Menu();
	~Menu();
	static int printMenu();

	//_func
	int addShape();

	//_addFunc
	void addArrow(std::string name);
	void addCircle(std::string name);
	void addTriangle(std::string name);
	void addRectangle(std::string name);

	static int count;
	//get info
	Shape* getShape();
	int secMenu();
	void moveShape(Shape* shape);
	void removShape(Shape* shape);

	//delet all shapes
	void deleteAllShapes();
private: 
	
	std::vector<Shape*> _shapes;
	Canvas _canvas;
	 
};



