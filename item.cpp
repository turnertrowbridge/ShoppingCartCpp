// item.cpp
#include "item.h"

Item::Item() : name(""), id(0), price(0.00), dealApplied(false) {}

Item::Item(const std::string &name, int id, double price)
    : name(name), id(id), price(price) {
    dealApplied = false;
}

Item::Item(const std::string &name, int id, double price, bool dealApplied,
           const std::set<Deal*> &deals)
    : name(name), id(id), price(price), dealApplied(dealApplied), deals(deals) {
}

const std::string &Item::getName() const { return name; }
int Item::getId() const { return id; }
double Item::getPrice() const { return price; }
bool Item::getDealApplied() const { return dealApplied; }
std::set<Deal*> Item::getDeals() const { return deals; }

void Item::setDealApplied(bool dealApplied) { this->dealApplied = dealApplied; }
void Item::addDeal(Deal* deal) { deals.insert(deal); }
