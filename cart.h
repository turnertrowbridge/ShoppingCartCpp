// cart.h
#ifndef CART_H
#define CART_H

#include "item.h"
#include "deal.h"
#include <vector>
#include <unordered_map>

class Cart {
    std::vector<Item> items;
    std::unordered_map<int, Deal> dealsMap;
    int totalPrice;
    int totalItems;
    std::vector<Deal> currentDeals;

public:
    Cart();
    void addItem(Item item);
    void removeItem(Item item);
    void addDeal(Deal deal);
    int getTotalPrice();
    int getTotalItems();
    void applyDeals();
    void checkout();
};

#endif
