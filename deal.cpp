// deal.cpp

#include "deal.h"

Deal::Deal(const std::string &name, int id) : name(name), id(id) {}

int Deal::getId() const {
    return id;
}

std::string Deal::getName() {
    return name;
}

std::vector<Item>
Deal::apply(std::vector<std::pair<Item, int>> &itemsMap) {
    return {};
}
