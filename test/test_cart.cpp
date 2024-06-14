#include "../buyThreeOneFreeDeal.h"
#include "../cart.h"
#include "../item.h"
#include "../threeForTwoDeal.h"
#include <cassert>
#include <iostream>

void testAddItem() {
    Cart cart;
    Item apple("Apple", 1, 0.60);
    cart.addItem(apple);

    auto items = cart.getCart();
    assert(items.size() == 1);
    assert(items[0].getName() == "Apple");
    assert(items[0].getPrice() == 0.60);

    std::cout << "testAddItem passed!" << std::endl;
}

// Test applying deals to items
// Expected output: Three For Two Deal applied to 1 apple and Buy Three One Free
// Deal applied to 1 orange
void testApplyDeals1() {
    Cart cart;
    Deal* threeFor2Deal = new ThreeForTwoDeal("Three For Two Deal", 1);
    Deal* oneFreeDeal = new BuyThreeOneFreeDeal("Buy Three One Free Deal", 2);

    Item apple("Apple", 1, 0.60);
    Item orange("Orange", 2, 0.25);

    apple.addDeal(threeFor2Deal);
    orange.addDeal(oneFreeDeal);

    cart.addDeal(threeFor2Deal);
    cart.addDeal(oneFreeDeal);

    cart.addItem(apple);
    cart.addItem(apple);
    cart.addItem(apple);
    cart.addItem(orange);
    cart.addItem(orange);
    cart.addItem(orange);

    cart.checkout();

    std::vector<
        std::pair<std::string, std::vector<std::pair<std::string, double>>>>
        discountedItems = cart.getDiscountedItems();
    auto discountedItemNames = cart.getDiscountedItems();
    std::vector<
        std::pair<std::string, std::vector<std::pair<std::string, double>>>>
        expectedDiscountedItems = {{"Three For Two Deal",
                                    {
                                        {"Apple", 0.60},
                                    }},
                                   {"Buy Three One Free Deal",
                                    {
                                        {"Orange", 0.25},
                                    }}};

    assert(
        discountedItemNames ==
        expectedDiscountedItems); // 1 apple and 1 orange should be discounted

    std::cout << "Testing 3 items with one deal and 3 items with the other..." << std::endl;
    std::cout << "\tCorrect items are discounted!" << std::endl;
    double price = cart.getTotalPrice();
    double tolerance = 1e-9; // Small tolerance for floating-point comparison
    assert(std::fabs(price - 2.55) < tolerance);
    std::cout << "\tTotal price is correct!" << std::endl;
    assert(std::fabs(cart.getTotalDiscount() - 0.85) < tolerance);
    std::cout << "\tTotal discount is correct!" << std::endl;
    
    delete threeFor2Deal;
    delete oneFreeDeal;
}

// Test both deals applied to the same item
// Expected: Three For Two Deal applied to 1 apple
void testApplyDeals2() {
    Cart cart;
    Deal* threeFor2Deal = new ThreeForTwoDeal("Three For Two Deal", 1);
    Deal* oneFreeDeal = new BuyThreeOneFreeDeal("Buy Three One Free Deal", 2);

    Item apple("Apple", 1, 0.60);
    Item orange("Orange", 2, 0.25);

    apple.addDeal(threeFor2Deal);
    apple.addDeal(oneFreeDeal);

    cart.addDeal(threeFor2Deal);
    cart.addDeal(oneFreeDeal);

    cart.addItem(apple);
    cart.addItem(apple);
    cart.addItem(apple);

    cart.checkout();

    std::vector<
        std::pair<std::string, std::vector<std::pair<std::string, double>>>>
        discountedItems = cart.getDiscountedItems();
    auto discountedItemNames = cart.getDiscountedItems();
    std::vector<
        std::pair<std::string, std::vector<std::pair<std::string, double>>>>
        expectedDiscountedItems = {{"Three For Two Deal",
                                    {
                                        {"Apple", 0.60},
                                    }},
                                   {{"Buy Three One Free Deal"},
                                    {

                                    }}};

    assert(discountedItemNames ==
           expectedDiscountedItems); // 1 apple should be discounted

    std::cout << "Testing both deals on same item..." << std::endl;
    std::cout << "\tCorrect items are discounted!" << std::endl;
    double price = cart.getTotalPrice();
    double tolerance = 1e-9; // Small tolerance for floating-point comparison
    assert(std::fabs(price - 1.8) < tolerance);
    std::cout << "\tTotal price is correct!" << std::endl;
    assert(std::fabs(cart.getTotalDiscount() - 0.60) < tolerance);
    std::cout << "\tTotal discount is correct!" << std::endl;

    delete threeFor2Deal;
    delete oneFreeDeal;
}

// Test Buy Three One Free Deal
// Expected: Buy Three One Free Deal applied to 1 orange (cheapest)
void testApplyDeals3() {
    Cart cart;
    Deal* threeFor2Deal = new ThreeForTwoDeal("Three For Two Deal", 1);
    Deal* oneFreeDeal = new BuyThreeOneFreeDeal("Buy Three One Free Deal", 2);

    Item apple("Apple", 1, 0.60);
    Item orange("Orange", 2, 0.25);

    apple.addDeal(threeFor2Deal);
    apple.addDeal(oneFreeDeal);
    orange.addDeal(oneFreeDeal);

    cart.addDeal(threeFor2Deal);
    cart.addDeal(oneFreeDeal);

    cart.addItem(apple);
    cart.addItem(apple);
    cart.addItem(orange);

    cart.checkout();

    std::vector<
        std::pair<std::string, std::vector<std::pair<std::string, double>>>>
        discountedItems = cart.getDiscountedItems();
    auto discountedItemNames = cart.getDiscountedItems();
    std::vector<
        std::pair<std::string, std::vector<std::pair<std::string, double>>>>
        expectedDiscountedItems = {{"Three For Two Deal",
                                    {
                                    }},
                                   {"Buy Three One Free Deal",
                                    {
                                        {"Orange", 0.25},
                                    }}};

    assert(
        discountedItemNames ==
        expectedDiscountedItems); // 1 orange should be discounted
    std::cout << "Testing Buy Three One Free Deal for cheapest item discounted..." << std::endl;
    std::cout << "\tCorrect items are discounted!" << std::endl;
    double price = cart.getTotalPrice();
    double tolerance = 1e-9; // Small tolerance for floating-point comparison
    assert(std::fabs(price - 1.45) < tolerance);
    std::cout << "\tTotal price is correct!" << std::endl;
    assert(std::fabs(cart.getTotalDiscount() - 0.25) < tolerance);
    std::cout << "\tTotal discount is correct!" << std::endl;

    delete threeFor2Deal;
    delete oneFreeDeal;
}

// Test Item can be applied to both deals
// Expected: Three For Two Deal applied to 1 apple and Buy Three One Free Deal
// applied to 1 orange
void testApplyDeals4() {
    Cart cart;
    Deal* threeFor2Deal = new ThreeForTwoDeal("Three For Two Deal", 1);
    Deal* oneFreeDeal = new BuyThreeOneFreeDeal("Buy Three One Free Deal", 2);

    Item apple("Apple", 1, 0.60);
    Item orange("Orange", 2, 0.25);

    apple.addDeal(threeFor2Deal);
    apple.addDeal(oneFreeDeal);
    orange.addDeal(oneFreeDeal);

    cart.addDeal(threeFor2Deal);
    cart.addDeal(oneFreeDeal);

    cart.addItem(apple);
    cart.addItem(apple);
    cart.addItem(apple);
    cart.addItem(apple);
    cart.addItem(apple);
    cart.addItem(orange);

    cart.checkout();

    std::vector<
        std::pair<std::string, std::vector<std::pair<std::string, double>>>>
        discountedItems = cart.getDiscountedItems();
    auto discountedItemNames = cart.getDiscountedItems();
    std::vector<
        std::pair<std::string, std::vector<std::pair<std::string, double>>>>
        expectedDiscountedItems = {{"Three For Two Deal",
                                    {
                                        {"Apple", 0.60},
                                    }},
                                   {"Buy Three One Free Deal",
                                    {
                                        {"Orange", 0.25},
                                    }}};

    assert(
        discountedItemNames ==
        expectedDiscountedItems); // 1 apple and 1 orange should be discounted
    std::cout << "Testing if both deals with 5 of one item and 1 of another item" << std::endl;
    std::cout << "\tCorrect items are discounted!" << std::endl;
    double price = cart.getTotalPrice();
    double tolerance = 1e-9; // Small tolerance for floating-point comparison
    assert(std::fabs(price - 3.25) < tolerance);
    std::cout << "\tTotal price is correct!" << std::endl;
    assert(std::fabs(cart.getTotalDiscount() - 0.85) < tolerance);
    std::cout << "\tTotal discount is correct!" << std::endl;

    delete threeFor2Deal;
    delete oneFreeDeal;
}

int main() {
    testAddItem();
    testApplyDeals1();
    testApplyDeals2();
    testApplyDeals3();
    testApplyDeals4();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
