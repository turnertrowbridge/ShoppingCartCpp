// cart.h
#ifndef SHOPPINGCART_CART_H
#define SHOPPINGCART_CART_H

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
    std::set<Deal*> deals;
    std::unordered_map<int, Deal*> dealMap;
    std::unordered_map<int, std::vector<Item*>>
        itemsEligibleForDealMap;
    std::unordered_map<int, Deal*> dealsIdMap;
    std::vector<Deal*> dealOrder;
    std::vector<std::pair<Deal*, std::vector<Item*>>> discountedItemsVector;
    std::vector<Item*> itemsPointerVector;
public:
    Cart();
    ~Cart();
    void addItem(Item item);
    void removeItem(int index);
    void addDeal(Deal* deal);
    std::vector<Item> getCart();
    double getTotalPrice() const;
    int getTotalItems() const;
    double getTotalDiscount() const;
    std::vector<std::pair<std::string, std::vector<std::pair<std::string, double>>>> getDiscountedItems();
    std::unordered_map<int, std::pair<Item, int>> makeItemsMap();
    void checkout();
};

#endif // SHOPPINGCART_CART_H
