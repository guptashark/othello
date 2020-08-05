#include <iostream>

#include "game.h"

using namespace std;

int main(int argc, char * argv[]) {

	(void)argc;
	(void)argv;

	cout << "Othello" << endl << endl;

	char player_color = 'B';

	game g(true);

	g.print_board();

	while ( true ) {

		int row = -1;
		int col = -1;

		cout << "Please enter a move: ";
		cin >> row;
		cin >> col;

		g.set_disk(row, col, player_color);

		g.print_board();

		player_color = g.opponent_tile(player_color);
	}


	return 0;
}
