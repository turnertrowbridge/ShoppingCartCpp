// deal.h
#ifndef DEAL_H
#define DEAL_H

#include <memory>
#include <vector>

class Item;

class Deal {
protected:
    std::string name;
    int id;
    std::vector<std::string> itemsAssociatedNames;

public:
    Deal(const std::string& name, int id);
    std::string getName();
    int getId() const;
    virtual std::vector<std::shared_ptr<Item>> apply(std::vector<std::shared_ptr<Item>>& items) = 0;
    virtual ~Deal() = default;
    void addItemAssociatedName(std::string name);
    std::vector<std::string> getItemsAssociatedNames();
};

#endif
