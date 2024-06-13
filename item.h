// item.h
#ifndef SHOPPINGCART_ITEM_H
#define SHOPPINGCART_ITEM_H

#include "deal.h"
#include <memory>
#include <set>
#include <string>
#include <vector>

class Item {
    std::string name;
    int id;
    double price;
    bool dealApplied;
    std::set<std::shared_ptr<Deal>> deals;

public:
    Item();
    Item(const std::string &name, int id, double price);
    Item(const std::string &name, int id, double price, bool dealApplied,
         const std::set<std::shared_ptr<Deal>>& deals);

    const std::string &getName() const;
    int getId() const;
    double getPrice() const;
    bool getDealApplied() const;
    std::set<std::shared_ptr<Deal>> getDeals() const;

    void setDealApplied(bool applied);
    void addDeal(std::shared_ptr<Deal> deal);
};

#endif // SHOPPINGCART_ITEM_H
