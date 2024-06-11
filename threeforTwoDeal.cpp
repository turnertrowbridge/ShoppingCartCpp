// threeForTwoDeal.cpp

#include "threeForTwoDeal.h"
#include <iostream>

threeForTwoDeal::threeForTwoDeal(int id) : id(id) {}

int threeForTwoDeal::getId() {
    return id;
}

std::vector<Item> threeForTwoDeal::apply (
    std::unordered_map<int, std::pair<Item, int>>& itemsMap) {
    std::vector<Item> discounted;
    for (auto &entry : itemsMap) {
        auto &item = entry.second.first;
        int &itemCount = entry.second.second;

        const auto &itemDiscounts = item.getDealIds();
        if (itemDiscounts.find(this->getId()) != itemDiscounts.end()) {
            while (itemCount > 2) {
                discounted.push_back(item);
                itemCount -= 3;
            }
        }
    }

    return discounted;
}
