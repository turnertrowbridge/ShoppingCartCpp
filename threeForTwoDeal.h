// threeForTwoDeal.h
#ifndef THREEFORTWODEAL_H
#define THREEFORTWODEAL_H

#include "deal.h"
#include "item.h"
#include <vector>
#include <unordered_map>

class threeForTwoDeal : public Deal {
public:
    threeForTwoDeal(const std::string& name, int id);

    std::vector<Item> apply(std::vector<std::pair<Item, int>>& itemsMap) override;
};

#endif
