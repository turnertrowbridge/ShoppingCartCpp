// deal.h
#ifndef DEAL_H
#define DEAL_H

#include "item.h"
#include <vector>

class Deal {
protected:
    int id;

public:
    Deal(int id);
    virtual int getId();
    virtual std::vector<Item> apply(std::unordered_map<int, std::pair<Item, int>>& itemsMap) = 0;
};

#endif
