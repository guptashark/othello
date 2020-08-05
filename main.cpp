#include <iostream>

#include "game.h"

using namespace std;

int main(int argc, char * argv[]) {

	(void)argc;
	(void)argv;

	cout << "Othello" << endl << endl;


	game g;

	g.mark_possible_moves('w');

	g.print_board();

	return 0;
}
