// threeForTwoDeal.h
#ifndef THREEFORTWODEAL_H
#define THREEFORTWODEAL_H

#include "deal.h"
#include "item.h"
#include <vector>
#include <unordered_map>

class threeForTwoDeal : Deal {
    int id;
public:
    threeForTwoDeal(int id);
    int getId();
    std::vector<Item> apply(std::unordered_map<int, std::pair<Item, int>>& itemsMap);
};

#endif
