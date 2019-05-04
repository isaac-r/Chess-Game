#include "Game.h"

Game::Game(Player player_1, Player player_2, Board game_board) {

	std::cout << "Enter player 1 name:" << std::endl;
	std::cin >> name_1;

	std::cout << "Enter player 2 name:" << std::endl;
	std::cin >> name_2;

	Player white("White", name_1);
	Player black("Black", name_2);
	player_1 = white;
	player_2 = black;
	board = game_board;

	board.create();
	board.show();

	// Put this in a while loop depending on winner or not
	bool game_won = false;

	while (game_won == false) {

		bool test = is_game_over(player_1, player_2, board);
		game_won = test;

		board.move(player_1);
		board.show();

		test = is_game_over(player_1, player_2, board); // This will become is king in check function
		game_won = test;

		board.move(player_2);
		board.show();

	}
}

bool Game::is_game_over(Player player_1, Player player_2, Board board) {
	int counter = 0; // Check if king is in check
	std::string King_Array[2];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board(i, j).get_piece() != nullptr) {
				if (board(i, j).get_piece_name() == "King") {
					King_Array[counter] = board(i, j).get_piece_colour();
					counter++;
				}
			}
		}
	}
	std::cout << "Number of kings remaining = " << counter << std::endl;
	if (counter > 1) {
		return false;
	}
	else { 
		if (King_Array[0] == "White") {
			std::cout << "Winner winner chicken dinner" << std::endl;
			std::cout << player_1.get_player_name() << " is the winner!" << std::endl;
			exit(1);
		}
		else {
			std::cout << "Winner winner chicken dinner" << std::endl;
			std::cout << player_2.get_player_name() << " is the winner!" << std::endl;
			exit(1);
		}
		return true; }
}