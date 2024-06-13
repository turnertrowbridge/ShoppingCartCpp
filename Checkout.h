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
    std::shared_ptr<Cart> cart;
    double totalPrice;
    int totalItems;
    double totalDiscount;
    std::vector<Item> items;
    std::vector<std::shared_ptr<Deal>> deals;

public:
    Checkout();
    void displayFinalReceipt();
    void displayCheckout();
    void displayMainMenu();
    void displayDeals();
    std::vector<Item> getItems() const;
    void displayItems() const;
    void displayCart();
    void setUp();
};

#endif // CHECKOUT_H
