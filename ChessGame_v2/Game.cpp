#include "Game.h"

Game::Game(Player player_1, Player player_2, Board game_board) {
	Player white("White");
	Player black("Black");
	player_1 = white;
	player_2 = black;
	board = game_board;

	board.create();
	board.show();

	// Put this in a while loop depending on winner or not
	bool game_won = false;

	while (game_won == false) {

		bool test = is_game_over(board);

		board.move(player_1);
		board.show();
		
		board.move(player_2);
		board.show();

		test = is_game_over(board); // This will become is king in check function

		if (test == true) {
			std::cout << "Winner winner chicken dinner" << std::endl;
			game_won = true;
			exit(1);
		}

		else { game_won = false; }



	}
}

bool Game::is_game_over(Board board) {
	int counter = 0; // Check if king is in check
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board(i, j).get_piece() != nullptr) {
				if (board(i, j).get_piece_name() == "King") {
					counter++;
				}
			}
		}
	}
	std::cout << "Number of kings remaining = " << counter << std::endl;
	if (counter > 1) {
		return false;
	}
	else { return true; }
}