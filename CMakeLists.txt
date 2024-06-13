cmake_minimum_required(VERSION 3.28)
project(ShoppingCart)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Catapult
        cart.cpp
        cart.h
        deal.cpp
        deal.h
        item.cpp
        item.h
        main.cpp
        threeforTwoDeal.cpp
        threeForTwoDeal.h
        buyThreeOneFreeDeal.cpp
        checkout.cpp)
