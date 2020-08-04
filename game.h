#ifndef GAME_H
#define GAME_H

class game {
	private:
		char board[8][8];

		// tile validations.

		// check that the tile exists on the board.
		bool is_valid_tile(int row, int col);

		// check that the tile is unoccupied.
		// Assumption: the tile indicated is valid.
		bool is_unoccupied_tile(int row, int col);
	public:
		game(void);

		void print_board(void);

		friend void
		test_is_valid_tile(void);

		friend void
		test_is_unoccupied_tile_at_startup(void);
};

#endif
