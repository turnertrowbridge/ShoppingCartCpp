// threeForTwoDeal.cpp

#include "threeForTwoDeal.h"
#include <memory>

ThreeForTwoDeal::ThreeForTwoDeal(const std::string &name, int id)
    : Deal(name, id) {}

std::vector<std::shared_ptr<Item>>
ThreeForTwoDeal::apply(std::vector<std::shared_ptr<Item>>& items) {
    std::vector<std::shared_ptr<Item>> discounted;

    // itemId : (Count, Items[])
    std::unordered_map<int, std::pair<int, std::vector<std::shared_ptr<Item>>>> itemsMap;


    // Add items to HashMap and their quantity
    for (auto &item : items) {
        int itemId = item->getId();
        // Check if a deal has already been applied
        if (item->getDealApplied()) {
            continue;
        }
        if (itemsMap.find(itemId) == itemsMap.end()) {
            itemsMap[itemId] = std::make_pair(1, std::vector<std::shared_ptr<Item>>{item});
        } else {
            itemsMap[itemId].first++;
            itemsMap[itemId].second.push_back(item);
        }
    }

    for (auto &entry : itemsMap) {
        int &itemCount = entry.second.first;
        auto itemsVector = entry.second.second;

        while (itemCount >= 3) {
            auto item = itemsVector.back();
            item->setDealApplied(true);
            itemsVector.pop_back();

            discounted.push_back(item);
            itemCount -= 3;
        }
    }

    return discounted;
}
