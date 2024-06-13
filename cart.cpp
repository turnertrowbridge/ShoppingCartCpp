// cart.cpp

#include "cart.h"
#include <iostream>
#include <memory>

Cart::Cart() {}

void Cart::addItem(Item item) {
    items.push_back(item);
}

void Cart::removeItem(Item item) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i].getId() == item.getId()) {
            items.erase(items.begin() + i);
            break;
        }
    }
}

std::vector<Item> Cart::getCart() {
    return items;
}

double Cart::getTotalPrice() {
    return totalPrice;
}

int Cart::getTotalItems() {
    return totalItems;
}

double Cart::getTotalDiscount() {
    return totalDiscount;
}

void Cart::addDeal(std::shared_ptr<Deal> deal) {
    deals.insert(deal);
    dealsIdMap[deal->getId()] = deal;
    dealOrder.push_back(deal);
}


std::vector<std::vector<std::pair<std::string, double>>> Cart::getDiscountedItems() {
    std::vector<std::vector<std::pair<std::string, double>>> discountedItems;
    for (const auto& pair: discountedItemsVector) {
        std::shared_ptr<Deal> deal = pair.first;
        const std::vector<std::shared_ptr<Item>>& discountedItemsVector = pair.second;
        std::vector<std::pair<std::string, double>> singleItemDiscounts;
        for (const auto& item : discountedItemsVector) {
            singleItemDiscounts.push_back(std::make_pair(item->getName(), item->getPrice()));
        }
        discountedItems.push_back(singleItemDiscounts);
    }
    return discountedItems;
}

std::unordered_map<int, std::pair<Item, int>> Cart::makeItemsMap() {
    // Create HashMap to keep track of amount of items
    std::unordered_map<int,std::pair<Item, int>> itemsMap;

    // Add items to HashMap and their quantity
    for (const Item& item : items) {
        int itemId = item.getId();
        if (itemsMap.find(itemId) == itemsMap.end()) {
            itemsMap[itemId] = std::make_pair(item, 1);
        } else {
            itemsMap[itemId].second++;
        }
    }
    return itemsMap;
}

void Cart::checkout() {
    totalPrice = 0.0;
    totalDiscount = 0.0;
    // Apply deals and display total info

    // Add undiscounted price of all items
    for (const Item& item : items) {
        totalPrice += item.getPrice();
    }
    totalItems = items.size();
    
    // Add empty vector for each deal
    for (const auto& deal : deals) {
        itemsEligibleForDealMap[deal->getId()] = std::vector<std::shared_ptr<Item>>();
    }

    std::vector<std::shared_ptr<Item>> itemsPointerVector;
    for (const Item& item : items) {
        itemsPointerVector.push_back(std::make_shared<Item>(item));
    }
   
    // Add items for each deal
    for (const auto& item: itemsPointerVector) {
        std::set<std::shared_ptr<Deal>> itemDeals = item->getDeals();
        for (const auto& deal : itemDeals) {
            int dealId = deal->getId();
            if (dealsIdMap.find(dealId) != dealsIdMap.end()) {
                itemsEligibleForDealMap[dealId].push_back(item);
            }
        }
    }


    // Apply deals
    for (const auto& deal : dealOrder) {
        std::vector<std::shared_ptr<Item>> discountedItems = deal->apply(itemsEligibleForDealMap[deal->getId()]);
        discountedItemsVector.emplace_back(deal, discountedItems);
        for (const auto& item : discountedItems) {
            totalDiscount += item->getPrice();
        }
    }
}
