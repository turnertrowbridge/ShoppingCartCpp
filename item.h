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
    std::set<Deal*> deals;

public:
    Item();
    Item(const std::string &name, int id, double price);
    Item(const std::string &name, int id, double price, bool dealApplied,
         const std::set<Deal*>& deals);

    const std::string &getName() const;
    int getId() const;
    double getPrice() const;
    bool getDealApplied() const;
    std::set<Deal*> getDeals() const;

    void setDealApplied(bool applied);
    void addDeal(Deal* deal);
};

#endif // SHOPPINGCART_ITEM_H
