// buyThreeOneFreeDeal.h
#ifndef SHOPPINGCART_BUYTHREEONEFREEDEAL_H
#define SHOPPINGCART_BUYTHREEONEFREEDEAL_H

#include "deal.h"
#include "item.h"
#include <algorithm>
#include <deque>

class BuyThreeOneFreeDeal : public Deal {
public:
    BuyThreeOneFreeDeal(const std::string& name, int id);

    std::vector<std::shared_ptr<Item>> apply(std::vector<std::shared_ptr<Item>>& items) override;
};

#endif // SHOPPINGCART_BUYTHREEONEFREEDEAL_H
