CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++17

SRC = main.cpp game.cpp


all:
	$(CXX) $(CXXFLAGS) $(SRC)
	./a.out
