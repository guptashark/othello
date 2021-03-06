CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++17

SRC = main.cpp game.cpp
TEST_SRC = othello_tests.cpp game.cpp

all: othello othello_tests

othello: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o othello
	./othello

othello_tests: $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o othello_tests
	./othello_tests
