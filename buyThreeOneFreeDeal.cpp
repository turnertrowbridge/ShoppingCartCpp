// buyThreeOneFreeDeal.cpp
#include "buyThreeOneFreeDeal.h"

BuyThreeOneFreeDeal::BuyThreeOneFreeDeal(const std::string &name, int id)
    : Deal(name, id) {}

std::vector<std::shared_ptr<Item>>
BuyThreeOneFreeDeal::apply(std::vector<std::shared_ptr<Item>>& items) {
    std::vector<std::shared_ptr<Item>> discountedItems;

    // Convert vector to deque
    std::deque<std::shared_ptr<Item>> itemsDeque;
    for (auto &item : items) {
        // Check if a deal has already been applied
        if (item->getDealApplied()) {
            continue;
        }
        itemsDeque.push_back(item);
    }

    // Sort deque
    std::sort(itemsDeque.begin(), itemsDeque.end(),
              [](const std::shared_ptr<Item>& a, const std::shared_ptr<Item>& b) {
                  return a->getPrice() < b->getPrice();
              });

    // Apply deal to deque
    while (itemsDeque.size() >= 3) {
        // Add the cheapest item to the discounted items
        discountedItems.push_back(itemsDeque.front());
        itemsDeque.front()->setDealApplied(true);

        // Remove the cheapest item from the deque
        // And mark the two most expensive items and remove them
        itemsDeque.pop_front();
        itemsDeque.back()->setDealApplied(true);
        itemsDeque.pop_back();
        itemsDeque.back()->setDealApplied(true);
        itemsDeque.pop_back();
    }
    return discountedItems;
}
