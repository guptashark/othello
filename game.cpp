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

// check that the tile is on the board.
bool game::is_valid_tile(int row, int col) {
	if ( ! ( 0 <= row && row < 8 )) return false;
	if ( ! ( 0 <= col && col < 8 )) return false;

	return true;
}

// check that the tile is unoccupied.
bool game::is_unoccupied_tile(int row, int col) {
	if ( board[row][col] != ' ' ) {
		return false;
	} else {
		return true;
	}
}

char game::opponent_tile(char c) {
	if ( c == 'b') {
		return 'w';
	} else {
		return 'b';
	}
}

int game::analyze_direction
(int row, int col, char c, int d_r, int d_c) {

	int score = 0;

	row = row + d_r;
	col = col + d_c;

	while ( is_valid_tile(row, col)) {

		if ( is_unoccupied_tile(row, col)) return 0;
		if ( board[row][col] == c ) return score;

		score++;
		row = row + d_r;
		col = col + d_c;
	}

	// if we exit the loop, then we've run off the
	// board and the score is 0.
	return 0;
}

void game::mark_possible_moves(char c) {

	char marked_tiles[8][8];

	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			marked_tiles[i][j] = ' ';
		}
	}

	for ( int i = 0; i < 8; i++) {
		for ( int j = 0; j < 8; j++) {

			int score = 0;

			if ( is_unoccupied_tile(i, j) ) {
				score = analyze_move(i, j, c);
			}

			if ( score > 0 ) {
				marked_tiles[i][j] = 'O';
			}
		}
	}

	// now, mark the actual board.
	for ( int i = 0; i < 8; i++) {
		for ( int j = 0; j < 8; j++) {
			if ( marked_tiles[i][j] == 'O') {
				board[i][j] = 'O';
			}
		}
	}
}

int game::analyze_move
(int row, int col, char c) {

	int score = 0;

	// north west, north, north east
	score += analyze_direction(row, col, c, -1, -1);
	score += analyze_direction(row, col, c, -1, 0);
	score += analyze_direction(row, col, c, -1, 1);

	score += analyze_direction(row, col, c, 0, 1);

	score += analyze_direction(row, col, c, 1, 1);
	score += analyze_direction(row, col, c, 1, 0);
	score += analyze_direction(row, col, c, 1, -1);

	score += analyze_direction(row, col, c, 0, -1);

	return score;
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
