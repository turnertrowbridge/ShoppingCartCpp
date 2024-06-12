// buyThreeOneFreeDeal.cpp
//
#include "buyThreeOneFreeDeal.h"

BuyThreeOneFreeDeal::BuyThreeOneFreeDeal(const std::string &name, int id)
    : Deal(name, id) {}

std::vector<std::shared_ptr<Item>>
BuyThreeOneFreeDeal::apply(std::vector<std::shared_ptr<Item>>& items) {
    std::vector<std::shared_ptr<Item>> discountedItems;

    // Convert vector to deque
    std::deque<std::shared_ptr<Item>> itemsDeque;
    for (auto &item : items) {
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
        // And the two most expensive items
        itemsDeque.pop_front();
        itemsDeque.pop_back();
        itemsDeque.pop_back();
    }
    return discountedItems;
}