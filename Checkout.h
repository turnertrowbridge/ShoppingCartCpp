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
    std::shared_ptr<Cart> cart;
    double totalPrice;
    int totalItems;
    double totalDiscount;
    std::vector<Item> items;
    std::vector<std::shared_ptr<Deal>> deals;

public:
    Checkout();
    void setUp();
    std::vector<Item> getItems() const;

    static int getValidIntInput(const std::string& prompt);
    static void addDealToItem(const std::shared_ptr<Deal>& deal, Item& item);

    void displayItems() const;
    void displayCart();
    void displayDeals();
    void displayFinalReceipt();
    void displayCheckout();
    void displayMainMenu();
};

#endif // SHOPPINGCART_CHECKOUT_H
