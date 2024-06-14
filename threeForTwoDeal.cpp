// threeForTwoDeal.cpp
#include "threeForTwoDeal.h"

ThreeForTwoDeal::ThreeForTwoDeal(const std::string &name, int id)
    : Deal(name, id) {}

std::vector<Item*>
ThreeForTwoDeal::apply(std::vector<Item*>& items) {
    std::vector<Item*> discounted;

    // itemId : (Count, Items[])
    std::unordered_map<int, std::pair<int, std::vector<Item*>>> itemsMap;

    // Add items to HashMap and their quantity
    for (auto &item : items) {
        int itemId = item->getId();
        // Check if a deal has already been applied
        if (item->getDealApplied()) {
            continue;
        }

        // Add item to map or update count
        if (itemsMap.find(itemId) == itemsMap.end()) {
            itemsMap[itemId] = std::make_pair(1, std::vector<Item*>{item});
        } else {
            itemsMap[itemId].first++;
            itemsMap[itemId].second.push_back(item);
        }
    }

    // Apply deal to items
    for (auto &entry : itemsMap) {
        int &itemCount = entry.second.first;
        auto itemsVector = entry.second.second;

        while (itemCount >= 3) {
            auto item = itemsVector.back();
            // Apply deal and add discounted item to vector
            item->setDealApplied(true);
            itemsVector.pop_back();
            discounted.push_back(item);

            // Mark other two items as deal applied
            itemsVector.back()->setDealApplied(true);
            itemsVector.pop_back();

            itemsVector.back()->setDealApplied(true);
            itemsVector.pop_back();

            itemCount -= 3;
        }
    }

    return discounted;
}
