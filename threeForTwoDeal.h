// threeForTwoDeal.h
#ifndef THREEFORTWODEAL_H
#define THREEFORTWODEAL_H

#include "deal.h"
#include "item.h"

class ThreeForTwoDeal : public Deal {
public:
    ThreeForTwoDeal(const std::string& name, int id);

    std::vector<std::shared_ptr<Item>> apply(std::vector<std::shared_ptr<Item>>& items) override;
};

#endif
