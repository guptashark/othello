#include <iostream>
#include <string>
#include <sstream>

#include "game.h"

using namespace std;

void get_input(int & row, int & col) {

	cout << "Please enter a move: ";

	bool valid_input = false;

	do {
		string input;

		getline(cin, input);
		stringstream ss(input);

		if ( ss >> row >> col ) {
			valid_input = true;
		} else {
			cout << "Please enter a valid pair of numbers: ";
			valid_input = false;
		}

	} while ( valid_input == false );
}

int main(int argc, char * argv[]) {

	(void)argc;
	(void)argv;

	cout << "Othello" << endl << endl;

	char player_color = 'B';

	game g(true);

	g.print_board();

	while ( true ) {

		int row;
		int col;

		get_input(row, col);

		g.set_disk(row, col, player_color);

		g.print_board();

		player_color = g.opponent_tile(player_color);
	}


	return 0;
}
