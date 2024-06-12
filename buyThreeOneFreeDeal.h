// buyThreeOneFreeDeal.h
#ifndef BUYTHREEONEFREEDEAL_H
#define BUYTHREEONEFREEDEAL_H

#include "deal.h"
#include "item.h"
#include <memory>
#include <vector>
#include <algorithm>
#include <deque>

class BuyThreeOneFreeDeal : public Deal {
public:
    BuyThreeOneFreeDeal(const std::string& name, int id);

    std::vector<std::shared_ptr<Item>> apply(std::vector<std::shared_ptr<Item>>& items) override;
};

#endif
