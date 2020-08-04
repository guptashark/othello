#include <iostream>
#include <cassert>

#include "game.h"

using std::cout;
using std::endl;

void test_is_valid_tile(void) {

	game g;

	// test that every row col pair that is valid,
	// is in fact valid according to our testing fn.
	for ( int i = 0; i < 8; i++) {
		for ( int j = 0; j < 8; j++) {
			assert( g.is_valid_tile( i, j ) );
		}
	}

	// test negative numbers.

	// test that so long as row is neg,
	// the result is always false.
	assert( g.is_valid_tile(-1, -2) == false);
	assert( g.is_valid_tile(-1, 0) == false);
	assert( g.is_valid_tile(-1, 2) == false);
	assert( g.is_valid_tile(-1, 9) == false);

	// test that so long as col is neg,
	// the result is always false.
	assert( g.is_valid_tile(-2, -1) == false);
	assert( g.is_valid_tile(0, -1) == false);
	assert( g.is_valid_tile(2, -1) == false);
	assert( g.is_valid_tile(10, -1) == false);

	// test large numbers.

	// test that so long as row is larger than 8,
	// the result is always false.
	assert( g.is_valid_tile(10, -2) == false);
	assert( g.is_valid_tile(10, 0) == false);
	assert( g.is_valid_tile(10, 2) == false);
	assert( g.is_valid_tile(10, 9) == false);

	// test that so long as col is larger than 8,
	// the result is always false
	assert( g.is_valid_tile(-2, 10) == false);
	assert( g.is_valid_tile(0, 10) == false);
	assert( g.is_valid_tile(2, 10) == false);
	assert( g.is_valid_tile(10, 10) == false);
}

void test_is_unoccupied_tile_at_startup(void) {

	// test that at startup, the unoccupied tile
	// test works perfectly.

	game g;

	bool correct_vals[8][8];

	for ( int i = 0; i < 8; i++) {
		for ( int j = 0; j < 8; j++) {
			correct_vals[i][j] = true;
		}
	}

	correct_vals[3][3] = false;
	correct_vals[3][4] = false;
	correct_vals[4][3] = false;
	correct_vals[4][4] = false;

	for ( int i = 0; i < 8; i++) {
		for ( int j = 0; j < 8; j++) {
			bool res = g.is_unoccupied_tile(i,j);
			assert( res == correct_vals[i][j]);
		}
	}
}

int main(void) {

	test_is_valid_tile();
	test_is_unoccupied_tile_at_startup();

	cout << "All tests passed!" << endl;
	return 0;
}
