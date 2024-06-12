// item.cpp
#include "item.h"
#include <memory>
#include <iostream>

Item::Item() : id(0), name(""), price(0.00) {}

Item::Item(const std::string& name, int id, double price)
    : name(name), id(id), price(price) {}

Item::Item(const std::string& name, int id, double price, const std::set<std::shared_ptr<Deal>>& deals) :
    name(name), id(id), price(price), deals(deals) {}

void Item::addDeal(std::shared_ptr<Deal> deal) {
    deals.insert(deal);
    std::cout << "Deal added to item: " << deal->getId() << std::endl;
}

std::set<std::shared_ptr<Deal>> Item::getDeals() const{
    return deals;
}

int Item::getId() const {
    return id;
}

const std::string& Item::getName() const {
    return name;
}

double Item::getPrice() const {
    return price;
}