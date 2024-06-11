// main.cpp

#include "item.h"
#include "cart.h"
#include "threeForTwoDeal.h"

#include <iostream>

int main() {
    Item item1("apple", 1, 0.60);
    Item item2("banana", 2, 0.20);
    Item item3("orange", 3, 0.25);
    Item item4("kiwi", 4, 0.40);
    Item item5("apple", 1, 0.30);
    Item item6("apple", 1, 0.20);

    Cart cart;
    cart.addItem(item1);
    cart.addItem(item2);
    cart.addItem(item3);
    cart.addItem(item4);
    cart.addItem(item5);

    threeForTwoDeal deal1(1);
    cart.addDeal(deal1);

    cart.checkout();

    return 0;
}


