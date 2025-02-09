#include <iostream>
#include <vector>
#include <memory>
#include "GroceryItem.hpp"

int main() {
    std::vector<std::unique_ptr<GroceryItem>> shoppingCart;

    std::cout << "Welcome to Kroger.  Place grocery items into your shopping cart by entering each item's information.\n"
              << "   enclose string entries in quotes, separate fields with comas\n"
              << "   for example:  \"00016000306707\", \"Betty Crocker\", \"Betty Crocker Double Chocolate Chunk Cookie Mix\", 17.19\n"
              << "   Enter CTL-Z (Windows) or CTL-D (Linux) to quit\n\n";

    GroceryItem item;
    std::cout << "Enter UPC, Product Brand, Product Name, and Price\n";
    while (std::cin >> item) {
        shoppingCart.push_back(std::make_unique<GroceryItem>(item));
        std::cout << "Item added to shopping cart: " << item << "\n\n";
        std::cout << "Enter UPC, Product Brand, Product Name, and Price\n";
    }

    std::cout << "\n\nHere is an itemized list of the items in your shopping cart:\n";
    for (auto it = shoppingCart.rbegin(); it != shoppingCart.rend(); ++it) {
        std::cout << **it << '\n';
    }

    return 0;
}
