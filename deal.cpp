// deal.cpp

#include "deal.h"

Deal::Deal(const std::string &name, int id) : name(name), id(id) {}

int Deal::getId() const {
    return id;
}

std::string Deal::getName() {
    return name;
}

std::vector<std::shared_ptr<Item>>
Deal::apply(std::vector<std::shared_ptr<Item>>& items) {
    return {};
}

void Deal::addItemAssociatedName(std::string name) {
    itemsAssociatedNames.push_back(name);
}

std::vector<std::string> Deal::getItemsAssociatedNames() {
    return itemsAssociatedNames;
}
