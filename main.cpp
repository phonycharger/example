#include <iostream>
#include <sstream>
#include "GroceryItem.hpp"

int main()
{
    // Construct some items
    const GroceryItem item1("Kit Kat Bar", "Nestle", "00003400012345", 1.25);
    GroceryItem item2("Reese Peanut Butter Cups", "Hershey", "00034000020706", 2.49);

    // Print them
    std::cout << "Item 1: " << item1 << "\n"
              << "Item 2: " << item2 << "\n\n";

    // Compare them
    if(item1 < item2)
        std::cout << "Item1 <  Item2\n";
    else if(item1 > item2)
        std::cout << "Item1 >  Item2\n";
    else
        std::cout << "Item1 == Item2\n";

    // Read a new item from a string stream
    std::istringstream in("\"000111222333\", \"Mars\", \"Snickers\", 1.99");
    GroceryItem item3;
    if(in >> item3)
    {
        std::cout << "\nSuccessfully read an item:\n";
        std::cout << "Item 3: " << item3 << "\n";
    }
    else
    {
        std::cout << "\nFailed to read item3!\n";
    }

    return 0;
}
