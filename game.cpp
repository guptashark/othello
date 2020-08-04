#include <iostream>

#include "game.h"

using std::cout;
using std::endl;

game::game(void) {

	for ( int i = 0; i < 8; i++) {
		for ( int j = 0; j < 8; j++) {
			board[i][j] = ' ';
		}
	}

	board[3][3] = 'b';
	board[4][4] = 'b';

	board[3][4] = 'w';
	board[4][3] = 'w';
}

void game::print_board(void) {

	// Ideally replace these with
	// box drawing characters.
	const char vert_line = '|';
	const char horiz_line = '-';
	const char intersect = '+';
	const char right_t = '|';
	const char down_t = '+';
	const char bottom_right_corner = '+';

	// print the col numbers

	cout << "    ";

	for ( int i = 0; i < 8; i++ ) {

		cout << " ";
		cout << i;
		cout << " ";

		cout << vert_line;
	}

	cout << endl;

	for ( int i = 0; i < 8; i++ ) {

		// print the tile borders.
		for ( int j = 0; j < 8; j++ ) {
			cout << horiz_line;
			cout << horiz_line;
			cout << horiz_line;

			cout << intersect;
		}

		// print the last column border.
		cout << horiz_line;
		cout << horiz_line;
		cout << horiz_line;

		cout << right_t;

		cout << endl;

		// print the row number
		cout << " " << i << " " << vert_line;

		// print the tile.
		for ( int j = 0; j < 8; j++ ) {

			cout << " ";
			cout << board[i][j];
			cout << " ";

			cout << vert_line;
		}

		cout << endl;
	}

	// print the bottom border.
	for ( int j = 0; j < 8; j++ ) {
		cout << horiz_line;
		cout << horiz_line;
		cout << horiz_line;

		cout << down_t;
	}

	// print the last column border.
	cout << horiz_line;
	cout << horiz_line;
	cout << horiz_line;

	cout << bottom_right_corner;

	cout << endl;
}
