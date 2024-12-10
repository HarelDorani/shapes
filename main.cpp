#include "Menu.h"

int main()
{
    std::string name;
    int choice = 0;
    int inChoice = 0;
    Shape* inShape = nullptr; // Initialize to null
    Menu menu;

    //a lopp for as long as the 
    do
    {
        choice = menu.printMenu();

        switch (choice)
        {
        // Add a shape
        case 1:
            inChoice = menu.addShape();

            std::cout << "Enter shape name:" << std::endl;
            std::cin.ignore(); // Clear the input buffer
            std::getline(std::cin, name);
            switch (inChoice)
            {
                //add arrow
            case 1:
                menu.addArrow(name);
                break;
                //add circle
            case 2:
                menu.addCircle(name);
                break;
                //add triangle
            case 3:
                menu.addTriangle(name);
                break;
                //add rectangle
            case 4:
                menu.addRectangle(name);
                break;
            default:
                std::cout << "Invalid shape type selected." << std::endl;
                break;
            }
            break;

        // Delete or move a shape
        case 2:
            inShape = menu.getShape();
            if (!inShape)
            {
                std::cout << "Invalid shape selected." << std::endl;
                break;
            }

            inChoice = menu.secMenu();
            switch (inChoice)
            {
            //moving shape
            case 1:
                menu.moveShape(inShape);
                std::cout << "Shape has moved." << std::endl;
                break;
            //removing shape
            case 2:
                menu.removShape(inShape); // Corrected function name
                std::cout << "Shape has been removed." << std::endl;
                break;
            default:
                std::cout << "Invalid operation selected." << std::endl;
                break;
            }
            break;

           // Delete all shapes
        case 3:
            menu.deleteAllShapes();
            std::cout << "All shapes deleted." << std::endl;
            break;

        default:
            if (choice != 4)
                std::cout << "Invalid menu option selected." << std::endl;
            break;
        }
    } while (choice != 4);

    menu.deleteAllShapes(); // Final cleanup
    return 0;
}
