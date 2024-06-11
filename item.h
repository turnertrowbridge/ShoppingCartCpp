// item.h
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include <set>

class Item {
    std::string name;
    int id;
    double price;
    std::set<int> dealIds;

public:
    Item(const std::string&, int id, double price);
    void setDealIds(int dealId);
    int getId() const;
    double getPrice();
    const std::set<int>& getDealIds() const;
};

#endif
