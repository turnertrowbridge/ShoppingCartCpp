#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "buyThreeOneFreeDeal.h"
#include "threeForTwoDeal.h"
#include "cart.h"
#include "deal.h"
#include "item.h"
#include <memory>
#include <vector>

class Checkout {
    Cart cart;
    double totalPrice;
    int totalItems;
    double totalDiscount;
    std::vector<Item> items;

public:
    Checkout();
    void displayFinalReceipt();
    void menu();
    std::vector<Item> getItems() const;
    void displayItems();
    void displayCart();
};

#endif // CHECKOUT_H
