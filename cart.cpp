// cart.cpp

#include "cart.h"
#include <iostream>

Cart::Cart() {}

void Cart::addItem(Item item) {
    items.push_back(item);
}

void Cart::removeItem(Item item) {
    // Remove item from cart
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

    // Find deals and apply them
    auto itemsMap = makeItemsMap();
    
    // Add empty vector for each deal
    for (const auto& deal : deals) {
        itemsEligibleForDealMap[deal->getId()] = std::vector<std::pair<Item, int>>();
    }

    // Add items and quantities to itemsEligibleForDealMap
    for (const auto& pair : itemsMap) {
        int itemId = pair.first;
        Item item = pair.second.first;
        int quantity = pair.second.second;
        std::set<std::shared_ptr<Deal>> itemDeals = item.getDeals();
        // Check all the deals on an item and add item to itemsEligibleForDealMap if it is eligible
        for (const auto& deal : itemDeals){
            int dealId = deal->getId();
            if (dealsIdMap.find(dealId) != dealsIdMap.end()) {
                itemsEligibleForDealMap[dealId].push_back(std::make_pair(item, quantity));
            }
        }
    }


    std::vector<std::pair<std::shared_ptr<Deal>,std::vector<Item>>> discountedItemsVector;  // <Deal, <Item, Quantity>>;
    // Apply deals
    for (const auto& pair : dealsIdMap) {
        auto deal = pair.second;
        std::vector<Item> discountedItems = deal->apply(itemsEligibleForDealMap[deal->getId()]);
        discountedItemsVector.emplace_back(deal, discountedItems);
        for (const Item& item : discountedItems) {
            totalDiscount += item.getPrice();
        }
    }

    // Display discounted items
    std::cout << "Discounted Items: " << std::endl;
    for (const auto& pair: discountedItemsVector) {
        std::shared_ptr<Deal> deal = pair.first;
        std::vector<Item> discountedItems = pair.second;
        std::cout << deal->getName() << ":" << std::endl;
        for (const auto&  discountItem : discountedItems) {
            std::cout << "   - " << discountItem.getName() << " ~ $" << discountItem.getPrice() << std::endl;
        }
    }

    std::cout << "Total Price: $" << totalPrice << std::endl;
    std::cout << "Total Items: " << totalItems << std::endl;
    std::cout << "Total Discount: $" << totalDiscount << std::endl;
    std::cout << "Final Price: $" << totalPrice - totalDiscount << std::endl;

        
}
