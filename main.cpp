// main.cpp

#include "item.h"
#include "cart.h"
#include "threeForTwoDeal.h"
#include <iomanip>

#include <iostream>

int main() {
    auto deal = std::make_shared<threeForTwoDeal>("Three For Two Deal",1);

    Item apple("Apple", 1, 0.60);
    Item orange("Orange", 2, 0.25);
    Item banana("Banana", 3, 0.20);
    Item papaya("Papaya", 4, 0.50);
    apple.addDeal(deal);
    orange.addDeal(deal);


    Cart cart;
    cart.addDeal(deal);
    cart.addItem(apple);
    cart.addItem(apple);
    cart.addItem(apple);
    cart.addItem(apple);
    cart.addItem(orange);
    cart.addItem(orange);
    cart.addItem(apple);
    cart.addItem(orange);
    cart.addItem(banana);
    cart.addItem(apple);
    cart.addItem(papaya);


    std::cout << "Cart Items: " << std::endl;

    std::cout << std::fixed << std::setprecision(2);

    for (auto& item : cart.getCart()) {
        std::cout << item.getName() << " ~ $" << item.getPrice() << std::endl;
    }

    cart.checkout();


    return 0;
}


