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

	board[3][3] = 'B';
	board[4][4] = 'B';

	board[3][4] = 'W';
	board[4][3] = 'W';

	is_marked = false;
}

// check that the tile is on the board.
bool game::is_valid_tile(int row, int col) {
	if ( ! ( 0 <= row && row < 8 )) return false;
	if ( ! ( 0 <= col && col < 8 )) return false;

	return true;
}

// check that the tile is unoccupied.
bool game::is_unoccupied_tile(int row, int col) {
	if ( board[row][col] == ' ' ) {
		return true;
	} else if ( board[row][col] == 'O') {
		return true;
	} else {
		return false;
	}
}

char game::opponent_tile(char c) {
	if ( c == 'B') {
		return 'W';
	} else {
		return 'B';
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

	is_marked = true;
}

void game::clear_marks(void) {
	for ( int i = 0; i < 8; i++) {
		for ( int j = 0; j < 8; j++) {
			if ( board[i][j] == 'O') {
				board[i][j] = ' ';
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

int game::set_disk_directional
(int row, int col, char c, int d_r, int d_c) {

	int score = 0;

	row = row + d_r;
	col = col + d_c;

	int row_indices[8];
	int col_indices[8];


	while ( is_valid_tile(row, col)) {

		if ( is_unoccupied_tile(row, col)) return 0;


		// actually flip the tiles we've stored
		// the indices of.
		if ( board[row][col] == c ) {

			for (int i = 0; i < score; i++) {

				int r_index = row_indices[i];
				int c_index = col_indices[i];

				board[r_index][c_index] = c;
			}

			return score;
		}

		row_indices[score] = row;
		col_indices[score] = col;

		score++;

		row = row + d_r;
		col = col + d_c;
	}


	// if we exit the loop, then we've run off the
	// board and the score is 0.
	return 0;
}

bool game::set_disk(int row, int col, char c) {

	// analyze the move - it may not be the
	// case that the spot is marked because
	// the player isn't playing with marked
	// tiles.

	int score = analyze_move(row, col, c);

	if ( score == 0 ) return false;

	// otherwise, set the disks.
	score += set_disk_directional(row, col, c, -1, -1);
	score += set_disk_directional(row, col, c, -1, 0);
	score += set_disk_directional(row, col, c, -1, 1);

	score += set_disk_directional(row, col, c, 0, 1);

	score += set_disk_directional(row, col, c, 1, 1);
	score += set_disk_directional(row, col, c, 1, 0);
	score += set_disk_directional(row, col, c, 1, -1);

	score += set_disk_directional(row, col, c, 0, -1);

	board[row][col] = c;

	if ( is_marked ) {
		clear_marks();
	}

	mark_possible_moves( opponent_tile(c) );

	return true;
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
