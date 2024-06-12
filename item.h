// item.h
#ifndef ITEM_H
#define ITEM_H

#include "deal.h"
#include <memory>
#include <set>
#include <string>
#include <vector>

class Item {
    std::string name;
    int id;
    double price;
    std::set<std::shared_ptr<Deal>> deals;

public:
    Item();
    Item(const std::string &name, int id, double price);
    Item(const std::string &name, int id, double price,
         const std::set<std::shared_ptr<Deal>>& deals);
    void addDeal(std::shared_ptr<Deal> deal);
    std::set<std::shared_ptr<Deal>> getDeals() const;
    int getId() const;
    const std::string &getName() const;
    double getPrice() const;
};

#endif
