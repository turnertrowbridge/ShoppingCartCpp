// cart.cpp

#include "cart.h"

Cart::Cart() {}

void Cart::addItem(Item item) {
    items.push_back(item);
}

void Cart::removeItem(Item item) {
    // Remove item from cart
}

void Cart::addDeal(Deal deal) {
    currentDeals.push_back(deal);
}

void Cart::applyDeals() {
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

    for (auto& deal : currentDeals) {
        deal->apply(itemsMap);
    }


}

void Cart::checkout() {
    // Apply deals and display total info
}
