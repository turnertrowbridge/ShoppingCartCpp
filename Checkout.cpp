#include "Checkout.h"
#include "deal.h"
#include <iomanip>
#include <iostream>

Checkout::Checkout() {
    totalPrice = 0;
    totalItems = 0;
    totalDiscount = 0;
    auto threeFor2Deal =
        std::make_shared<ThreeForTwoDeal>("Three For Two Deal", 1);
    auto oneFreeDeal =
        std::make_shared<BuyThreeOneFreeDeal>("Buy Three One Free Deal", 2);
    // Add items
    Item apple("Apple", 1, 0.60);
    Item orange("Orange", 2, 0.25);
    Item banana("Banana", 3, 0.20);
    Item papaya("Papaya", 4, 0.50);
    apple.addDeal(threeFor2Deal);
    orange.addDeal(threeFor2Deal);
    apple.addDeal(oneFreeDeal);
    banana.addDeal(oneFreeDeal);

    items.push_back(apple);
    items.push_back(orange);
    items.push_back(banana);
    items.push_back(papaya);

    cart.addDeal(threeFor2Deal);
    cart.addDeal(oneFreeDeal);
}

std::vector<Item> Checkout::getItems() const { return items; }

void Checkout::displayItems() {
    std::vector<Item> items = getItems();
    for (int i = 0; i < items.size(); i++) {
        std::cout << i + 1 << ". " << items[i].getName() << " ~ $"
                  << items[i].getPrice() << std::endl;
    }
}

void Checkout::displayCart() {
    std::vector<Item> items = cart.getCart();
    for (int i = 0; i < items.size(); i++) {
        std::cout << i + 1 << ". " << items[i].getName() << " ~ $"
                  << items[i].getPrice() << std::endl;
    }
}

void Checkout::displayFinalReceipt() {
    std::system("clear");
    std::cout << "Receipt: \n";
    std::cout << "Items purchased:" << std::endl;
    displayCart();

    std::cout << "\nDiscounted Items:" << std::endl;
    for (const auto &pair : cart.getDiscountedItems()) {
        for (const auto &item : pair) {
            std::cout << "  - " << item.first << " ~ $" << item.second
                      << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "Total Price: $" << cart.getTotalPrice() << std::endl;
    std::cout << "Total Items: " << cart.getTotalItems() << std::endl;
    std::cout << "Total Discount: $" << cart.getTotalDiscount() << std::endl;
    std::cout << "Final Price: $"
              << cart.getTotalPrice() - cart.getTotalDiscount() << std::endl;
}

void Checkout::menu() {
    while (true) {
        // Clear the console
        std::system("clear");

        // Set the precision for the output
        std::cout << std::fixed << std::setprecision(2);

        // Display items in the cart
        std::cout << "Items in Cart:" << std::endl;
        displayCart();

        // Display the menu
        std::cout << "Menu" << std::endl;
        std::cout << "1. Add Item" << std::endl;
        std::cout << "2. Remove Item" << std::endl;
        std::cout << "3. Checkout" << std::endl;
        std::cout << "4. Exit" << std::endl;

        std::cout << "Select an option: ";
        // Wait for user input
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            // Add item

            // Display items
            std::system("clear");
            std::cout << "Select an item to add to the cart:" << std::endl;
            displayItems();
            int itemChoice = 0;
            std::cout << "Select an item: ";
            std::cin >> itemChoice;
            cart.addItem(items[itemChoice - 1]);
            break;
        }
        case 2: {
            // Remove item
            std::cout << "Select an item to remove from cart:" << std::endl;
            std::system("clear");
            displayCart();
            int itemChoice = 0;
            std::cout << "Select an item: ";
            std::cin >> itemChoice;
            cart.removeItem(items[itemChoice - 1]);
            break;
        }
        case 3: {
            // Checkout
            cart.checkout();
            displayFinalReceipt();
            return;
        }
        case 4: {
            // Exit
            return;
        }
        default: {
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        }
    }
}
