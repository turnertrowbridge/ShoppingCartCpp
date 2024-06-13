# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++14 -Wall -g

# Include directories
INCLUDES = -I.

# Target executable
TARGET = ShoppingCart

# Source files
SRCS = main.cpp cart.cpp deal.cpp item.cpp threeForTwoDeal.cpp buyThreeOneFreeDeal.cpp checkout.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean

