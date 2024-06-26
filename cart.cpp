// cart.cpp
#include "cart.h"

Cart::Cart() {}

Cart::~Cart() {
    // Delete items from itemsPointerVector
    for (const auto& item : itemsPointerVector) {
        delete item;
    }
}

// Pass by value to create multiple items with the same name
void Cart::addItem(Item item) {
    items.push_back(item);
}

void Cart::removeItem(int index) {
    items.erase(items.begin() + index);
}

void Cart::addDeal(Deal* deal) {
    deals.insert(deal);
    dealsIdMap[deal->getId()] = deal;
    dealOrder.push_back(deal);
}

std::vector<Item> Cart::getCart() {
    return items;
}

double Cart::getTotalPrice() const {
    return totalPrice;
}

int Cart::getTotalItems() const {
    return totalItems;
}

double Cart::getTotalDiscount() const {
    return totalDiscount;
}

std::vector<std::pair<std::string, std::vector<std::pair<std::string, double>>>> Cart::getDiscountedItems() {
    // Create a vector of discounted items in form of (dealName, (itemName, itemPrice))
    std::vector<std::pair<std::string, std::vector<std::pair<std::string, double>>>> discountedItems;
    for (const auto& pair: discountedItemsVector) {
        Deal* deal = pair.first;
        const std::vector<Item*>& discountedItemsVector = pair.second;
        std::vector<std::pair<std::string, double>> singleItemDiscounts;
        for (const auto& item : discountedItemsVector) {
            singleItemDiscounts.push_back(std::make_pair(item->getName(), item->getPrice()));
        }
        discountedItems.push_back(std::make_pair(deal->getName(), singleItemDiscounts));
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

    // Add normal price of all items
    for (const Item& item : items) {
        totalPrice += item.getPrice();
    }
    totalItems = items.size();

    // Add empty vector for each deal
    for (const auto& deal : deals) {
        itemsEligibleForDealMap[deal->getId()] = std::vector<Item*>();
    }

    // Create a vector of shared pointers to items
    for (const Item& item : items) {
        itemsPointerVector.push_back(new Item(item));
    }

    // Add items for each deal
    for (const auto& item: itemsPointerVector) {
        std::set<Deal*> itemDeals = item->getDeals();
        for (const auto& deal : itemDeals) {
            int dealId = deal->getId();
            if (dealsIdMap.find(dealId) != dealsIdMap.end()) {
                itemsEligibleForDealMap[dealId].push_back(item);
            }
        }
    }


    // Apply deals
    for (const auto& deal : dealOrder) {
        std::vector<Item*> discountedItems = deal->apply(itemsEligibleForDealMap[deal->getId()]);
        discountedItemsVector.emplace_back(deal, discountedItems);
        for (const auto& item : discountedItems) {
            totalDiscount += item->getPrice();
        }
    }
}
