// threeForTwoDeal.cpp

#include "threeForTwoDeal.h"

threeForTwoDeal::threeForTwoDeal(const std::string& name, int id) : Deal(name, id) {}

std::vector<Item> threeForTwoDeal::apply (
    std::vector<std::pair<Item, int>>& itemsMap) {
    std::vector<Item> discounted;
    for (auto &entry : itemsMap) {
        auto &item = entry.first;
        int &itemCount = entry.second;

        while (itemCount > 2) {
            discounted.push_back(item);
            itemCount -= 3;
            }
        }

    return discounted;
}
