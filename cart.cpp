// cart.cpp

#include "cart.h"

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

int Cart::getTotalPrice() {
    return totalPrice;
}

int Cart::getTotalItems() {
    return totalItems;
}

int Cart::getTotalDiscount() {
    return totalDiscount;
}

void Cart::addDeal(Deal deal) {
    deals.insert(deal);
    dealIdMap[deal.getId()] = deal;
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
    // Apply deals and display total info
    
    // Add undiscounted price of all items
    for (const Item& item : items) {
        totalPrice += item.getPrice();
    }
    totalItems = items.size();

    // Find deals and apply them
    auto itemsMap = makeItemsMap();
    
    // Add empty vector for each deal
    for (Deal deal : deals) {
        itemsElgibleForDealMap[deal.getId()] = std::vector<std::pair<Item, int>>();
    }

    // Add items and quantities to itemsElgibleForDealMap
    for (const auto& pair : itemsMap) {
        int itemId = pair.first;
        Item item = pair.second.first;
        int quantity = pair.second.second;
        std::set<int> dealIds = item.getDealIds();
        // Check all the deals on an item and add item to itemsElgibleForDealMap if it is eligible
        for (int dealId : dealIds){
            if (dealIdMap.find(dealId) != dealIdMap.end()) {
                itemsElgibleForDealMap[dealId].push_back(std::make_pair(item, quantity));
            }
        }
    }

    // Apply deals
    for (const auto& pair : dealIdMap) {
        auto deal = pair.second;
        std::vector<Item> discountedItems = deal.apply(itemsElgibleForDealMap[deal.getId()]);
        for (Item item : discountedItems) {
            totalDiscount += item.getPrice();
        }
    }
        
}
