// cart.h
#ifndef CART_H
#define CART_H

#include "item.h"
#include "deal.h"
#include <vector>
#include <unordered_map>

class Cart {
    std::vector<Item> items;
    int totalPrice;
    int totalItems;

public:
    Cart();
    void addItem(Item item);
    void removeItem(Item item);
    std::vector<Item> getCart();
    int getTotalPrice();
    int getTotalItems();
    std::unordered_map<int, std::pair<Item, int>> makeItemsMap();
    void checkout();
};

#endif
