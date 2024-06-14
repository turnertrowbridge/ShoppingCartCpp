# Variables
CXX = g++
CXXFLAGS = -I../src -std=c++11

# Targets
all: test_cart

test_cart: test_cart.o cart.o item.o buyThreeOneFreeDeal.o threeForTwoDeal.o deal.o
	$(CXX) -o test_cart test_cart.o cart.o item.o buyThreeOneFreeDeal.o threeForTwoDeal.o deal.o

test_cart.o: test_cart.cpp
	$(CXX) $(CXXFLAGS) -c test_cart.cpp

cart.o: ../cart.cpp
	$(CXX) $(CXXFLAGS) -c ../cart.cpp -o cart.o

item.o: ../item.cpp
	$(CXX) $(CXXFLAGS) -c ../item.cpp -o item.o

buyThreeOneFreeDeal.o: ../buyThreeOneFreeDeal.cpp
	$(CXX) $(CXXFLAGS) -c ../buyThreeOneFreeDeal.cpp -o buyThreeOneFreeDeal.o

threeForTwoDeal.o: ../threeForTwoDeal.cpp
	$(CXX) $(CXXFLAGS) -c ../threeForTwoDeal.cpp -o threeForTwoDeal.o

deal.o: ../deal.cpp
	$(CXX) $(CXXFLAGS) -c ../deal.cpp -o deal.o

clean:
	rm -f *.o test_cart


