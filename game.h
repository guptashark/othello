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

		char opponent_tile(char c);

		// return the number of tiles flipped in the
		// specified direction if a tile of color c
		// was placed at row, col.
		//
		// d_r and d_c describe direction.
		// (delta r and delta c)
		int
		analyze_direction
		(int row, int col, char c, int d_r, int d_c);


		// return the number of tiles flipped if
		// a tile of color c was placed at (row, col).
		int
		analyze_move
		(int row, int col, char c);

	public:
		game(void);

		void print_board(void);

		// mark off on the board all the possible moves
		// for someone placing a tile of color c.
		void
		mark_possible_moves(char c);
		friend void
		test_is_valid_tile(void);

		friend void
		test_is_unoccupied_tile_at_startup(void);
};

#endif
