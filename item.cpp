// item.cpp
#include "item.h"

Item::Item(const std::string& name, int id, double price)
    : name(name), id(id), price(price) {}


void Item::setDealIds(int dealId) {
    dealIds.insert(dealId);
}

int Item::getId() const {
    return id;
}

const std::set<int>& Item::getDealIds() const {
    return dealIds;
}


