// deal.h
#ifndef DEAL_H
#define DEAL_H

#include "item.h"
#include <vector>

class Deal {
    int id;

public:
    int getId();
    std::vector<Item> apply(std::unordered_map<int, std::pair<Item, int>>& itemsMap);
};

#endif
