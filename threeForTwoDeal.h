// threeForTwoDeal.h
#ifndef THREEFORTWODEAL_H
#define THREEFORTWODEAL_H

#include "deal.h"
#include "item.h"
#include <vector>
#include <unordered_map>

class threeForTwoDeal : public Deal {
    int id;
public:
    threeForTwoDeal(int id);
    int getId() const override;
    std::vector<Item> apply(std::vector<std::pair<Item, int>>& itemsMap) override;
};

#endif
