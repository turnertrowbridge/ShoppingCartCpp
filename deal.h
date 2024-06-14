// deal.h
#ifndef SHOPPINGCART_DEAL_H
#define SHOPPINGCART_DEAL_H

#include <memory>
#include <vector>

class Item;

class Deal {
protected:
    std::string name;
    int id;
    std::vector<std::string> itemsAssociatedNames;

public:
    Deal(const std::string &name, int id);
    virtual ~Deal() = default;

    std::string getName();
    int getId() const;
    std::vector<std::string> getItemsAssociatedNames();

    void addItemAssociatedName(std::string name);

    virtual std::vector<Item*>
    apply(std::vector<Item*> &items) = 0;
};

#endif // SHOPPINGCART_DEAL_H
