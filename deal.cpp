// deal.cpp
#include "deal.h"

Deal::Deal(const std::string &name, int id) : name(name), id(id) {}

std::string Deal::getName() { return name; }

int Deal::getId() const { return id; }

std::vector<std::string> Deal::getItemsAssociatedNames() {
    return itemsAssociatedNames;
}

void Deal::addItemAssociatedName(std::string name) {
    itemsAssociatedNames.push_back(name);
}

std::vector<std::shared_ptr<Item>>
Deal::apply(std::vector<std::shared_ptr<Item>> &items) {
    return {};
}
