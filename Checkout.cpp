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

    deals.push_back(threeFor2Deal);
    deals.push_back(oneFreeDeal);
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
}

void Checkout::setUp() {
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

std::vector<Item> Checkout::getItems() const { return items; }

void Checkout::displayItems() const {
    std::vector<Item> items = getItems();
    for (int i = 0; i < items.size(); i++) {
        std::cout << i + 1 << ". " << items[i].getName() << " ~ $"
                  << items[i].getPrice() << std::endl;
    }
}

void Checkout::displayCart() {
    std::vector<Item> items = cart->getCart();
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

    auto discountedItems = cart->getDiscountedItems();
    bool hasDiscountedItems = false;

    // Check if there are any discounted items
    for (const auto &pair : discountedItems) {
        if (!pair.second.empty()) {
            hasDiscountedItems = true;
            break;
        }
    }

    if (hasDiscountedItems) {
        std::cout << "\nDiscounts applied:" << std::endl;
        for (const auto &pair : discountedItems) {
            if (!pair.second.empty()) {
                std::cout << "\n" << pair.first << std::endl;
                for (const auto &itemPair : pair.second) {
                    std::cout << "    - " << itemPair.first << " ~ $"
                              << itemPair.second << std::endl;
                }
            }
        }
    }

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

void Checkout::displayDeals() {
    for (const auto &deal : deals) {
        std::cout << deal->getName() << std::endl;
    }
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

        // Display the menu
        std::cout << "Menu" << std::endl;
        std::cout << "1. Add Item" << std::endl;
        std::cout << "2. Remove Item" << std::endl;
        std::cout << "3. Checkout" << std::endl;
        std::cout << "4. Show Deals" << std::endl;
        std::cout << "5. Exit" << std::endl;

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
            cart->addItem(items[itemChoice - 1]);
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
            cart->removeItem(items[itemChoice - 1]);
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
            std::cout << "Invalid choice. Please try again." << std::endl;
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
        int choice;
        std::cin >> choice;

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
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        }
    }
}
