// threeForTwoDeal.cpp

#include "threeForTwoDeal.h"
#include <iostream>

threeForTwoDeal::threeForTwoDeal(int id) : id(id) {}


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

        std::cout << "Discounted Items: " << std::endl;
        for (auto &item : discounted) {
            std::cout << item.getName() << " ~ $" << item.getPrice() << std::endl;
        }

    return discounted;
}
int threeForTwoDeal::getId() const { return id; }
