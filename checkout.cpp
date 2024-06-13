// checkout.cpp
#include "checkout.h"
#include "deal.h"
#include <iomanip>
#include <iostream>

Checkout::Checkout() {
    totalPrice = 0;
    totalItems = 0;
    totalDiscount = 0;

    // Create deals and add them
    auto threeFor2Deal =
        std::make_shared<ThreeForTwoDeal>("Three For Two Deal", 1);
    auto oneFreeDeal =
        std::make_shared<BuyThreeOneFreeDeal>("Buy Three One Free Deal", 2);
    deals.push_back(threeFor2Deal);
    deals.push_back(oneFreeDeal);

    // Create items
    Item apple("Apple", 1, 0.60);
    Item orange("Orange", 2, 0.25);
    Item banana("Banana", 3, 0.20);
    Item papaya("Papaya", 4, 0.50);

    // Associate deals with items
    addDealToItem(threeFor2Deal, apple);
    addDealToItem(threeFor2Deal, orange);
    addDealToItem(oneFreeDeal, apple);
    addDealToItem(oneFreeDeal, banana);

    // Add items to the inventory
    inventory.push_back(apple);
    inventory.push_back(orange);
    inventory.push_back(banana);
    inventory.push_back(papaya);
}

void Checkout::setUp() {
    // Make a new cart
    cart = std::make_shared<Cart>();
    totalPrice = 0;
    totalItems = 0;
    totalDiscount = 0;
    std::cout << "Items added to the checkout." << std::endl;

    // Add deals to cart
    for (const auto &deal : deals) {
        cart->addDeal(deal);
    }

    std::cout << "Deals added to the cart." << std::endl;
}

int Checkout::getValidIntInput(const std::string &prompt) {
    // Get valid integer input from the user, otherwise return -1 to go back
    std::cout << prompt;
    int input;
    std::cin >> input;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n'); // Clears input buffer if not int
        return -1;                   // Invalid input
    } else {
        return input;
    }
}

void Checkout::addDealToItem(const std::shared_ptr<Deal> &deal, Item &item) {
    // Add deal to item and item to deal
    item.addDeal(deal);
    deal->addItemAssociatedName(item.getName());
}

void Checkout::displayInventory() const {
    // Display items in inventory
    for (int i = 0; i < inventory.size(); i++) {
        std::cout << i + 1 << ". " << inventory[i].getName() << " ~ $"
                  << inventory[i].getPrice() << std::endl;
    }
}

void Checkout::displayCart() {
    // Display items in the cart
    std::vector<Item> items = cart->getCart();
    for (int i = 0; i < items.size(); i++) {
        std::cout << i + 1 << ". " << items[i].getName() << " ~ $"
                  << items[i].getPrice() << std::endl;
    }
}

void Checkout::displayDeals() {
    // Display deals and items associated with them
    for (const auto &deal : deals) {
        std::cout << deal->getName() << std::endl;
        bool hasItems = false;
        for (const auto &itemName : deal->getItemsAssociatedNames()) {
            std::cout << "  - " << itemName << std::endl;
            hasItems = true;
        }

        // If no deals are available, display a message
        if (!hasItems) {
            std::cout << "    No items available for this deal." << std::endl;
        }
    }

    std::cout << "\n\n\nPress any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
}

void Checkout::displayFinalReceipt() {
    std::system("clear");
    std::cout << "Receipt: \n";
    std::cout << "Items purchased:" << std::endl;
    displayCart();

    auto discountedItems = cart->getDiscountedItems();
    bool hasDiscountedItems = false;

    // Check if there are any discounted items
    for (const auto &pair : discountedItems) {
        if (!pair.second.empty()) {
            hasDiscountedItems = true;
            break;
        }
    }

    // Display discounted items
    if (hasDiscountedItems) {
        std::cout << "\nDiscounts applied:" << std::endl;
        for (const auto &pair : discountedItems) {
            if (!pair.second.empty()) {
                std::cout << "  " << pair.first << std::endl;
                for (const auto &itemPair : pair.second) {
                    std::cout << "    - " << itemPair.first << " ~ $"
                              << itemPair.second << std::endl;
                }
            }
        }
    }

    // Display totals
    std::cout << std::endl;
    std::cout << "Total Price: $" << cart->getTotalPrice() << std::endl;
    std::cout << "Total Items: " << cart->getTotalItems() << std::endl;
    std::cout << "Total Discount: $" << cart->getTotalDiscount() << std::endl;
    std::cout << "Final Price: $"
              << cart->getTotalPrice() - cart->getTotalDiscount() << std::endl;

    std::cout << "\n\n\nPress any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
}

void Checkout::displayCheckout() {
    while (true) {
        // Clear the console
        std::system("clear");

        // Set the precision for the output
        std::cout << std::fixed << std::setprecision(2);

        // Display items in the cart
        std::cout << "Items in Cart:" << std::endl;
        displayCart();
        std::cout << std::endl;

        // Display the menu
        std::cout << "Menu" << std::endl;
        std::cout << "1. Add Item" << std::endl;
        std::cout << "2. Remove Item" << std::endl;
        std::cout << "3. Checkout" << std::endl;
        std::cout << "4. Show Deals" << std::endl;
        std::cout << "5. Exit" << std::endl;

        // Wait for user input
        int choice = getValidIntInput("Select an option: ");

        switch (choice) {
        case 1: {
            // Add item
            std::system("clear");
            std::cout << "Select an item to add to the cart:" << std::endl;
            displayInventory();
            int itemChoice = getValidIntInput("Select an item: ");
            if (itemChoice > 0 && itemChoice <= inventory.size()) {
                cart->addItem(
                    inventory[itemChoice - 1]); // Pass item by value to create
                                                // multiple items
            }
            break;
        }
        case 2: {
            // Remove item
            std::system("clear");
            std::cout << "Select an item to remove from cart:" << std::endl;
            displayCart();
            int itemChoice = getValidIntInput("Select an item: ");
            if (itemChoice > 0 && itemChoice <= cart->getCart().size()) {
                cart->removeItem(itemChoice - 1);
            }
            break;
        }
        case 3: {
            // Checkout
            cart->checkout();
            displayFinalReceipt();
            return;
        }
        case 4: {
            // Show deals
            std::system("clear");
            std::cout << "Deals:" << std::endl;
            displayDeals();
            break;
        }
        case 5: {
            // Exit
            return;
        }
        default: {
            break;
        }
        }
    }
}

void Checkout::displayMainMenu() {
    while (true) {
        std::system("clear");
        std::cout << "Welcome to the Checkout" << std::endl;
        std::cout << "1. Start New Order" << std::endl;
        std::cout << "2. Exit" << std::endl;

        std::cout << "Select an option: ";
        int choice = getValidIntInput("");

        switch (choice) {
        case 1: {
            // Start new order
            std::cout << "Starting new order..." << std::endl;
            std::cout << "Cart created." << std::endl;
            setUp();
            displayCheckout();
            break;
        }
        case 2: {
            // Exit
            return;
        }
        default: {
            break;
        }
        }
    }
}
