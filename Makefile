# Makefile

# Compiler and flags
CXX = clang++ 
CXXFLAGS = -std=c++20 -Wall -Wextra -O2

# Target executable
TARGET = main

# Source files
SRCS = main.cpp

# Object files (optional for more complex projects)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Clean target to remove build artifacts
clean:
	rm -f $(TARGET) $(OBJS)