// cart.h
#ifndef CART_H
#define CART_H

#include "item.h"
#include "deal.h"
#include <vector>
#include <unordered_map>
#include <set>

class Cart {
    std::vector<Item> items;
    int totalPrice;
    int totalItems;
    int totalDiscount;
    std::set<Deal> deals;
    std::unordered_map<int, Deal> dealIdMap;
    std::unordered_map<int, std::vector<std::pair<Item, int>>> itemsElgibleForDealMap;
public:
    Cart();
    void addItem(Item item);
    void removeItem(Item item);
    void addDeal(Deal deal);
    std::vector<Item> getCart();
    int getTotalPrice();
    int getTotalItems();
    int getTotalDiscount();
    std::unordered_map<int, std::pair<Item, int>> makeItemsMap();
    void checkout();
};

#endif
