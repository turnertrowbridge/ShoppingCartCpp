// item.cpp
#include "item.h"
#include <memory>

Item::Item() : name(""), id(0), price(0.00), dealApplied(false) {}

Item::Item(const std::string &name, int id, double price)
    : name(name), id(id), price(price) {
    dealApplied = false;
}

Item::Item(const std::string &name, int id, double price, bool dealApplied,
           const std::set<std::shared_ptr<Deal>> &deals)
    : name(name), id(id), price(price), dealApplied(dealApplied), deals(deals) {
}

void Item::addDeal(std::shared_ptr<Deal> deal) { deals.insert(deal); }

void Item::setDealApplied(bool dealApplied) { this->dealApplied = dealApplied; }

std::set<std::shared_ptr<Deal>> Item::getDeals() const { return deals; }

int Item::getId() const { return id; }

const std::string &Item::getName() const { return name; }

double Item::getPrice() const { return price; }
