#include <iostream>

#include "game.h"

using namespace std;

int main(int argc, char * argv[]) {

	(void)argc;
	(void)argv;

	cout << "Othello" << endl << endl;


	game g;

	g.print_board();

	return 0;
}
