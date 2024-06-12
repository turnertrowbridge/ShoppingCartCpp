// deal.h
#ifndef DEAL_H
#define DEAL_H

#include <vector>

class Item;

class Deal {
    int id;

public:
    virtual ~Deal() = default;
    virtual int getId() const = 0;
    virtual std::vector<Item> apply(std::vector<std::pair<Item, int>>& itemsMap) = 0;
};

#endif
