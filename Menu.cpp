#include "Menu.h"

int Menu::count = 0;

Menu::Menu() 
{
	
}

Menu::~Menu()
{
	
}

//print the main menu
int Menu::printMenu()
{
	//get the choice and return it
	int choice = 0;
	std::cout << "Welcome to the shapre maker" << std::endl;
	do
	{
		std::cout << "plese enter 1-4" << std::endl;
		std::cout << "1- add shape" << std::endl;
		std::cout << "2- get info or change an existing shape" << std::endl;
		std::cout << "3- delete all shapes" << std::endl;
		std::cout << "4- exit" << std::endl;
		std::cin >> choice;

	} while (choice > 4 || choice < 1);


	return choice;
}

//the add shape function
int Menu::addShape()
{
	int choice = 0;
	//add onr to the shape count
	count++;
	//get the kind and return it
	do 
	{
		std::cout << "please enter 1-4" << std::endl;
		std::cout << "1- arrow" << std::endl;
		std::cout << "2- circle" << std::endl;
		std::cout << "3- triangle" << std::endl;
		std::cout << "4- rectangle" << std::endl;
		std::cin >> choice;
	} while (choice > 4 || choice < 1);

	return choice;
}

//adding arrow
void Menu::addArrow(std::string name)
{
	//get the info
	double x, y;
	std::cout << "enter point1 x" << std::endl;
	std::cin >> x;
	std::cout << "enter point1 y" << std::endl;
	std::cin >> y;
	Point one(x, y);
	std::cout << "enter point2 x" << std::endl;
	std::cin >> x;
	std::cout << "enter point2 y" << std::endl;
	std::cin >> y;
	Point two(x, y);

	//init an arrow and drow it
	Arrow* arrow = new Arrow(one, two, "arrow", name);
	_shapes.push_back(arrow); 
	arrow->draw(_canvas);
}

//adding circle
void Menu::addCircle(std::string name)
{
	double x = 0;
	double y = 0;
	double radius = 0;
	std::cout << "enter the middle point x" << std::endl;
	std::cin >> x;
	std::cout << "enter the middle y" << std::endl;
	std::cin >> y;
	Point middle(x, y);
	std::cout << "enter the radius" << std::endl;
	std::cin >> radius;
	
		//init and draw
	Circle* circle = new Circle(middle, radius, "arrow", name);
	this->_shapes.push_back(circle);
	circle->draw(this->_canvas);

}

void Menu::addTriangle(std::string name)
{
	// Get the points for the triangle
	double x, y;

	std::cout << "Enter point1 x: ";
	std::cin >> x;
	std::cout << "Enter point1 y: ";
	std::cin >> y;
	Point one(x, y);

	std::cout << "Enter point2 x: ";
	std::cin >> x;
	std::cout << "Enter point2 y: ";
	std::cin >> y;
	Point two(x, y);

	std::cout << "Enter point3 x: ";
	std::cin >> x;
	std::cout << "Enter point3 y: ";
	std::cin >> y;
	Point three(x, y);

	// Create the triangle dynamically
	Triangle* triangle = new Triangle(one, two, three, "triangle", name);

	// Add the triangle to the vector
	_shapes.push_back(triangle);

	// Draw the triangle on the canvas
	triangle->draw(_canvas);

	
}

//adding rectanglw
void Menu::addRectangle(std::string name)
{
	//get the info
	double x;
	double y;
	double width = 0;
	double length = 0;
	std::cout << "enter point1 x" << std::endl;
	std::cin >> x;
	std::cout << "enter point1 y" << std::endl;
	std::cin >> y;
	Point one(x, y);
	std::cout << "enter the width" << std::endl;
	std::cin >> width;
	std::cout << "enter the length" << std::endl;
	std::cin >> length;
	//init and draw
	myShapes::Rectangle* rectangle = new myShapes::Rectangle(one, length, width, "rectangle", name);
	this->_shapes.push_back(rectangle);
	rectangle->draw(this->_canvas);


}

//get the shape
Shape* Menu::getShape()
{
	int i = 0;
	int choice = 0;
	//print the shapes
	for (i = 0; i < count; i++)
	{
		std::cout << i + 1 <<":" << "  name: " << _shapes[i]->getName() << "  type: " << _shapes[i]->getType() << " area: " << _shapes[i]->getArea() << " parameter: " << _shapes[i]->getPerimeter() << std::endl;
	}
	//get the shape
	std::cout << "enter the number of the shape you want:  ";
	std::cin >> choice;
	//return the shape
	return _shapes[choice - 1];

}

//the secend menu 
int Menu::secMenu()
{
	//get the choice and return it
	int choice = 0;
	do
	{
		std::cout << "choose one of the following" << std::endl;
		std::cout << "1- move the shape" << std::endl;
		std::cout << "2- remove shape" << std::endl;
		std::cin >> choice;
	} while (choice < 1 || choice >2);

	return choice;
}

//function to kmkove the shape
void Menu::moveShape(Shape* shape)
{
	double x = 0;
	double y = 0;
	//get the info
	std::cout << "how mach would you like to move in the x ? " << std::endl;
	std::cin >> x;
	std::cout << "how mach would you like to move in the y ? " << std::endl;
	std::cin >> y;

	//mov the shape
	Point movPoint(x, y);

	shape->move(movPoint);

}

//remove shape
void Menu::removShape(Shape* shape)
{
	shape->clearDraw(this->_canvas);
}

//delete all shapes
void Menu::deleteAllShapes()
{
	int i = 0;
	for (i = 0; i < count; i++)
	{
		_shapes[i]->clearDraw(this->_canvas);
		this->removShape(_shapes[i]);
	}
}

