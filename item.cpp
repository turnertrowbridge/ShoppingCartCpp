// item.cpp
#include "item.h"

Item::Item() : id(0), name(""), price(0.00), dealIds({}) {}

Item::Item(const std::string& name, int id, double price)
    : name(name), id(id), price(price) {}

Item::Item(const std::string& name, int id, double price, const std::set<int>& dealIds) :
    name(name), id(id), price(price), dealIds(dealIds) {}

void Item::setDealIds(int dealId) {
    dealIds.insert(dealId);
}

int Item::getId() const {
    return id;
}

const std::string& Item::getName() const {
    return name;
}

const std::set<int>& Item::getDealIds() const {
    return dealIds;
}
double Item::getPrice() const {
    return price;
}
