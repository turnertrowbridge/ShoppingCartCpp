// deal.h
#ifndef DEAL_H
#define DEAL_H

#include <vector>

class Item;

class Deal {
protected:
    std::string name;
    int id;

public:
    Deal(const std::string& name, int id);
    std::string getName();
    int getId() const;
    virtual std::vector<Item> apply(std::vector<std::pair<Item, int>>& itemsMap) = 0;
    virtual ~Deal() = default;
};

#endif
