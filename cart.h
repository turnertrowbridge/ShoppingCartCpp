// cart.h
#ifndef CART_H
#define CART_H

#include "item.h"
#include "deal.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include <set>

class Cart {
    std::vector<Item> items;
    double totalPrice;
    int totalItems;
    double totalDiscount;
    std::set<std::shared_ptr<Deal>> deals;
    std::unordered_map<int, std::shared_ptr<Deal>> dealMap;
    std::unordered_map<int, std::vector<std::shared_ptr<Item>>>
        itemsEligibleForDealMap;
    std::unordered_map<int, std::shared_ptr<Deal>> dealsIdMap;
    std::vector<std::shared_ptr<Deal>> dealOrder;
    std::vector<std::pair<std::shared_ptr<Deal>,std::vector<std::shared_ptr<Item>>>> discountedItemsVector;
public:
    Cart();
    void addItem(Item item);
    void removeItem(int index);
    void addDeal(std::shared_ptr<Deal> deal);
    std::vector<Item> getCart();
    double getTotalPrice();
    int getTotalItems();
    double getTotalDiscount();
    std::unordered_map<int, std::pair<Item, int>> makeItemsMap();
    void checkout();
    std::vector<std::pair<std::string, std::vector<std::pair<std::string, double>>>> getDiscountedItems();
};

#endif
