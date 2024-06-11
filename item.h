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
    Item();
    Item(const std::string&, int id, double price);
    Item(const std::string& name, int id, double price, const std::set<int>& dealIds);
    void setDealIds(int dealId);
    std::set<int> getDealIds();
    int getId() const;
    const std::string& getName() const;
    double getPrice() const;
    const std::set<int>& getDealIds() const;
};

#endif
