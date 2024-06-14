// checkout.h
#ifndef SHOPPINGCART_CHECKOUT_H
#define SHOPPINGCART_CHECKOUT_H

#include "buyThreeOneFreeDeal.h"
#include "threeForTwoDeal.h"
#include "cart.h"
#include "deal.h"
#include "item.h"
#include <memory>
#include <vector>

class Checkout {
    Cart* cart;
    double totalPrice;
    int totalItems;
    double totalDiscount;
    std::vector<Item> inventory;
    std::vector<Deal*> deals;

public:
    Checkout();
    ~Checkout();
    void setUp();

    static int getValidIntInput(const std::string& prompt);
    static void addDealToItem(Deal* deal, Item& item);

    void displayInventory() const;
    void displayCart();
    void displayDeals();
    void displayFinalReceipt();
    void displayCheckout();
    void displayMainMenu();
};

#endif // SHOPPINGCART_CHECKOUT_H
