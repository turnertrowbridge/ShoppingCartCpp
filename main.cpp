// main.cpp

#include "item.h"
#include "cart.h"
#include "threeForTwoDeal.h"
#include "buyThreeOneFreeDeal.h"
#include <iomanip>

#include <iostream>

int main() {
    auto threeFor2Deal = std::make_shared<threeForTwoDeal>("Three For Two Deal",1);
    auto oneFreeDeal = std::make_shared<BuyThreeOneFreeDeal>("One Free Deal",2);

    Item apple("Apple", 1, 0.60);
    Item orange("Orange", 2, 0.25);
    Item banana("Banana", 3, 0.20);
    Item papaya("Papaya", 4, 0.50);
    apple.addDeal(threeFor2Deal);
    orange.addDeal(threeFor2Deal);
    apple.addDeal(oneFreeDeal);
    banana.addDeal(oneFreeDeal);


    Cart cart;
    cart.addDeal(threeFor2Deal);
    cart.addDeal(oneFreeDeal);

    cart.addItem(apple);
    cart.addItem(apple);
    cart.addItem(apple);
    cart.addItem(apple);
    cart.addItem(orange);
    cart.addItem(orange);
    cart.addItem(apple);
    cart.addItem(orange);
    cart.addItem(banana);
    cart.addItem(papaya);


    std::cout << "Cart Items: " << std::endl;

    std::cout << std::fixed << std::setprecision(2);

    for (auto& item : cart.getCart()) {
        std::cout << item.getName() << " ~ $" << item.getPrice() << std::endl;
    }

    cart.checkout();


    return 0;
}


