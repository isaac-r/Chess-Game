#include "Board.h"
#include<string>
#include<iostream>
#include "Piece.h"
#include "Player.h"
#include "Coord.h"

Board::Board() {
	// Initialise empty board
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = new Square(i, j);
		}
	}
}

//
// ######################################## Create board function ##########################################
//

void Board::create() { // Create a board
	// Set up the black pieces
	Piece* new_piece;
	new_piece = new Rook("Black");
	board[0][0]->set_piece(new_piece);
	new_piece = new Knight("Black");
	board[1][0]->set_piece(new_piece);
	new_piece = new Bishop("Black");
	board[2][0]->set_piece(new_piece);
	new_piece = new Queen("Black");
	board[3][0]->set_piece(new_piece);
	new_piece = new King("Black");
	board[4][0]->set_piece(new_piece);
	new_piece = new Bishop("Black");
	board[5][0]->set_piece(new_piece);
	new_piece = new Knight("Black");
	board[6][0]->set_piece(new_piece);
	new_piece = new Rook("Black");
	board[7][0]->set_piece(new_piece);

	for (int i = 0; i < 8; i++) {
		new_piece = new Pawn("Black");
		board[i][1]->set_piece(new_piece);
	}
	// Set up the white pieces
	new_piece = new Rook("White");
	board[0][7]->set_piece(new_piece);
	new_piece = new Knight("White");
	board[1][7]->set_piece(new_piece);
	new_piece = new Bishop("White");
	board[2][7]->set_piece(new_piece);
	new_piece = new Queen("White");
	board[3][7]->set_piece(new_piece);
	new_piece = new King("White");
	board[4][7]->set_piece(new_piece);
	new_piece = new Bishop("White");
	board[5][7]->set_piece(new_piece);
	new_piece = new Knight("White");
	board[6][7]->set_piece(new_piece);
	new_piece = new Rook("White");
	board[7][7]->set_piece(new_piece);

	for (int i = 0; i < 8; i++) {
		new_piece = new Pawn("White");
		board[i][6]->set_piece(new_piece);
	}
}

//
// ######################################## Show Board Function ##########################################
//

void Board::show() { // Show the board
	char Columns[8] = { 'A','B','C','D','E','F','G', 'H'};
	char Rows[8] = { '1','2','3','4','5','6','7','8' };
	std::cout << "   "; // Space between the Letters and edge
	for (int i = 0; i < 8; i++) {
		std::cout << "   " << Columns[i] << "    "; // Show letters
	}
	// Top row divide
	std::cout << std::endl << "  ";
	for (int i = 0; i < 10; i++) {
		std::cout << "######";
	}
	std::cout << "#######";
	std::cout << std::endl;
	// Second row divide
	for (int i = 0; i < 9; i++) {
		std::cout << "  #     ";
	}
	std::cout << std::endl;

	for (int i = 0; i < 8; i++) {
		
		if (i > 0) {
			std::cout << "      #       #       #       #       #       #       #       #    ";
			std::cout << std::endl << "  #######";
			for (int j = 0; j < 10; j++) {
				std::cout << "######";
			}
			std::cout << std::endl << "  #       #       #       #       #       #       #       #       #    " << std::endl;
		}
		for (int j = 0; j < 8; j++) {
			if (j == 0) {
				std::cout << Rows[i] << " # ";
			}
			char name = board[j][i]->display_square();
			std::cout << "  " << name << "   # ";
		}
		std::cout << std::endl << "  # ";
	}

	std::cout << "      #       #       #       #       #       #       #       #    ";
	std::cout << std::endl;
	std::cout << "  ";
	for (int i = 0; i < 10; i++) {
		std::cout << "######";
	}
	std::cout << "#######";
	std::cout << std::endl;

}

//
// ######################################## Move function ##########################################
//

void Board::move(Player player) { // Move a piece on the board
	
	std::cout << player.get_player_name() << " you are the " << player.get_player_colour() << " player" << std::endl;
	
	// First check if the king is in check 
	is_king_in_check();

	bool successful_move = false;
	// Start position
	int x_i = 0;
	int y_i = 0;
	// End position
	int x_f = 0;
	int y_f = 0;

	while (successful_move == false) {
		// Successful_move: boolean to check if a move has been successful, 
		// if not ask the user to try again and select a new piece/end position 

		bool piece_allowed = false;

		// While loop for selecting the start position
		while (piece_allowed == false) {

			std::cout << "Please pick a piece: " << std::endl;

			std::string start_position;

			Coord pos(start_position);
			/*std::string moves = pos.get_input();
			if (moves == "moves") {
				//get_allowed_moves;
				// Then ask the user to re_enter their piece position
			}*/

			x_i = pos.get_x();
			y_i = pos.get_y();

			Square *start = board[x_i][y_i];

			if (board[x_i][y_i]->get_piece() == nullptr) {
				piece_allowed = false;
				std::cout << "No piece selected" << std::endl;
			}

			else if (player.get_player_colour() != board[x_i][y_i]->get_piece_colour()) {
				piece_allowed = false;
				std::cout << "You chose...poorly" << std::endl;
			}
			else {
				piece_allowed = true;
			}

		}

		// Display the selected piece
		std::cout << "You have picked the " << board[x_i][y_i]->get_piece_colour() << " " << board[x_i][y_i]->get_piece_name() << std::endl;

		// Acquire the type of piece to be moved 
		std::string piece_type = board[x_i][y_i]->get_piece_name();
		std::string colour = board[x_i][y_i]->get_piece_colour();

		bool valid_move = false;

		// While loop for selecting the end position
		while (valid_move == false) {

			std::cout << "Please move this piece: " << std::endl;

			std::string end_position;

			Coord final_pos(end_position);

			/*std::string piece_moves = final_pos.get_input();
			if (piece_moves == "moves") {
				//get_allowed_piece_moves;
				// Then ask the user to re_enter their final piece position
			}*/

			x_f = final_pos.get_x();
			y_f = final_pos.get_y();

			Square *end = board[x_f][y_f];
			// Check if the detination is allowed 
			if (board[x_f][y_f]->get_piece() == nullptr || board[x_f][y_f]->get_piece_colour() != board[x_i][y_i]->get_piece_colour()) {
				// If there is no piece or the piece in the destination square is of the other colour check the path
				bool test;
				// Check if the move_pawn function needs to be called
				if (board[x_i][y_i]->get_piece_name() == "Pawn" && board[x_f][y_f]->get_piece() != nullptr) {
					// Special function to move the pawn
					std::string colour_1 = board[x_i][y_i]->get_piece_colour();
					std::string colour_2 = board[x_f][y_f]->get_piece_colour();
					test = board[x_i][y_i]->get_piece()->move_pawn(colour_1, colour_2, x_i, y_i, x_f, y_f);

					valid_move = test;
				}
				else {

					test = board[x_i][y_i]->get_piece()->move_piece(colour, x_i, y_i, x_f, y_f);

					if (test == true) {
						valid_move = check_path(x_i, y_i, x_f, y_f);
						if (valid_move == false) {
							std::cout << "Piece in the path!" << std::endl;
						}
					}
					else {
						valid_move = test; // Which will be false
					}
				}
			}

			else { std::cout << "This square contains a piece which belongs to you!" << std::endl; valid_move = false; }
			// If valid_move is false ask for user if they want to select a new piece or stay with the one they have selected
			// while within while 

			if (valid_move == false) {
				std::cout << "Would you like to pick a different piece? (y/n)" << std::endl;
				char result;
				std::cin >> result;
				if (result == tolower('Y')) {
					valid_move = true; // Set the valid move to true to break the loop
					successful_move = false;
				}
			}
			else {
				successful_move = true;
			}
		}
	}
	// Move the piece to this new square 
	// Check if the new square had a piece in it
	if (board[x_f][y_f]->get_piece() != nullptr){
		std::cout << player.get_player_name() << " captured the " << board[x_f][y_f]->get_piece_colour() << " " << board[x_f][y_f]->get_piece_name() << std::endl;
		// Delete the piece at this point 
		delete board[x_f][y_f]->get_piece();
		board[x_f][y_f]->set_piece(board[x_i][y_i]->get_piece()); // Delete the piece if it is captured
		board[x_i][y_i]->clear_square(); // Clear square (Delete the piece data in this square)
	}
	else {
		board[x_f][y_f]->set_piece(board[x_i][y_i]->get_piece()); // Delete the piece if it is captured
		board[x_i][y_i]->clear_square(); // Clear square (Delete the piece data in this square)
	}
	
}

//
// ######################################## Check Path function ##########################################
//

bool Board::check_path(int x_i, int y_i, int x_f, int y_f) {
	// Create a path to the new point consisting of squares in the board
	// I want to pick the squares in between the first and last squares
	// Use a multiplier call it m
	int m;
	int n;
	// Check Horizontal
	if (y_i - y_f == 0) {
		if (x_i > x_f) { m = -1; }
		else if (x_i < x_f) { m = 1; }
		else { return false; } // No move in x

		for (int i = x_i * m + 1; i < x_f * m; i++) { 
			int pos = i * m;
			bool test = board[pos][y_i]->check_occupation();
			if (test == true) {
				// Then there is a piece in the way
				//std::cout << "(Hor) There is a " << board[pos][y_i]->get_piece_name()<< 
					//" in the way!" << std::endl;
				return false;
			}
		}
	}
	// Check Vertical
	else if (x_i - x_f == 0) {
		if (y_i > y_f) { n = -1; }
		else if (y_i < y_f) { n = 1; }
		else { return false; } // No move in y 
		for (int i = y_i * n + 1; i < y_f * n; i++) {
			int pos = i * n;
			bool test = board[x_i][pos]->check_occupation();
			if (test == true) {
				// Then there is a piece in the way
				//std::cout << "(Vert) There is a " << board[x_i][pos]->get_piece_name() << 
					//" in the way! Block: " << x_i << "," << pos << std::endl;
				return false;
			}
		}
	}
	// Specialised else if statement for pawns 
	// This will need the pawn counter and to check if the squares diagonally in front of the pawn contains a piece
	else if (board[x_i][y_i]->get_piece_name() == "Pawn") {
		std::cout << "Specialised Pawn moves" << std::endl;
		// Pawns can only move horizontally (in the move_piece function check the movement)
		// if the pawn is in the start position it can move forward two
		// If the 
	}
	else {
		//std::cout << "Diagonal Move" << std::endl;
		if (x_i > x_f) { m = -1; }
		else if (x_i < x_f) { m = 1; }
		else { return false; } // No move in x 
		if (y_i > y_f) { n = -1; }
		else if (y_i < y_f) { n = 1; }
		else { return false; } // No move in y

		for (int i = x_i * m + 1; i < x_f * m; i++) {
			int x_pos = i * m;
			//bool test = board[pos][y_i]->check_occupation();
			for (int j = y_i * n + 1; j < y_f * n; j++) {
				int y_pos = j * n;
				bool test = board[x_pos][y_pos]->check_occupation();
				if (test == true) {
					// Then there is a piece in the way
					//std::cout << "(Diag) There is a " << board[x_pos][y_pos]->get_piece_name() <<
						//" in the way! Block: " << x_pos << "," << y_pos << std::endl;
					return false;
				}
			}
		}
	}
	return true;
}

//
// ###################################### Check path for check ###########################################
//

Piece* Board::check_path_2(int x_i, int y_i, int x_f, int y_f) {
	// Create a path to the new point consisting of squares in the board
	// I want to pick the squares in between the first and last squares
	// Use a multiplier call it m
	Piece* bad_piece = board[x_i][y_i]->get_piece();
	int m;
	int n;
	// Check Horizontal
	if (y_i - y_f == 0 && x_i - x_f != 0) {
		if (x_i > x_f) { m = -1; }
		else if (x_i < x_f) { m = 1; }

		for (int i = x_i * m + 1; i <= x_f * m; i++) {
			int pos = i * m;
			bool test = board[pos][y_i]->check_occupation();
			if (test == true) {
				// Find the piece here
				bad_piece = board[pos][y_i]->get_piece();
				return bad_piece;
			}
		}
	}
	// Check Vertical
	else if (x_i - x_f == 0 && y_i - y_f != 0) {
		if (y_i > y_f) { n = -1; }
		else if (y_i < y_f) { n = 1; }

		for (int i = y_i * n + 1; i <= y_f * n; i++) {
			int pos = i * n;
			bool test = board[x_i][pos]->check_occupation();
			if (test == true) {
				bad_piece = board[x_i][pos]->get_piece();
				return bad_piece;
			}
		}
	}
	else if (abs(x_f - x_i) == abs(y_f - y_i) && abs(x_f - x_i) > 0 && abs(y_f - y_i) > 0) {
		if (x_i > x_f) { m = -1; }
		else if (x_i < x_f) { m = 1; }
		if (y_i > y_f) { n = -1; }
		else if (y_i < y_f) { n = 1; }

		for (int i = x_i * m + 1; i <= x_f * m; i++) {
			int x_diag = i * m;
			for (int j = y_i * n + 1; j <= y_f * n; j++) {
				int y_diag = j * n;
				bool test = board[x_diag][y_diag]->check_occupation();
				if (test == true) {
					bad_piece = board[x_diag][y_diag]->get_piece();
					return bad_piece;
				}
			}
		}
	}
	else {
		bad_piece = board[x_i][y_i]->get_piece();
		return bad_piece;
	}
	return bad_piece = board[x_i][y_i]->get_piece();
	std::cout << "Not in check" << std::endl;
}

//
// ######################################## Check king function ##########################################
//

void Board::is_king_in_check() {
	// Get the colour of the king piece
	// Get the location of the king piece
	// Look for pieces of a different colour in the vertical, horizontal, diagonal paths
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			// Look for the king pieces on the board
			if (board[i][j]->get_piece() != nullptr && board[i][j]->get_piece_name() == "King") {
				// Find the position of this king 
				int x_king = board[i][j]->get_x();
				int y_king = board[i][j]->get_y();
				Piece* king_piece = board[i][j]->get_piece();
				//std::cout << board[i][j]->get_piece_colour() << " King position = " << x_king << "," << y_king << std::endl;

				// Initialising variables
				Coord king_pos(x_king, y_king);
				Piece* test_piece;

				// First look for pawns in front of king
				if (king_piece->get_colour() == "White") {
					if (x_king - 1 >= 0 && y_king - 1 >= 0 && board[x_king - 1][y_king - 1]->get_piece() != nullptr && board[x_king - 1][y_king - 1]->get_piece_name() == "Pawn"
						&& board[x_king - 1][y_king - 1]->get_piece_colour() == "Black") {
						std::cout << "White King is in check by Black Pawn" << std::endl;
					}
					else if(x_king + 1 < 7 && y_king - 1 >= 0 && board[x_king + 1][y_king - 1]->get_piece() != nullptr && board[x_king + 1][y_king - 1]->get_piece_name() == "Pawn"
						&& board[x_king + 1][y_king - 1]->get_piece_colour() == "Black"){
						std::cout << "White King is in check by Black Pawn" << std::endl;
					}
				}
				if (king_piece->get_colour() == "Black") {
					if (x_king - 1 >= 0 && y_king + 1 < 8 && board[x_king - 1][y_king + 1]->get_piece() != nullptr && board[x_king - 1][y_king + 1]->get_piece_name() == "Pawn"
						&& board[x_king - 1][y_king + 1]->get_piece_colour() == "White") {
						std::cout << "Black King is in check by Black Pawn" << std::endl;
					}
					else if (x_king + 1 < 8 && y_king + 1 < 8 && board[x_king + 1][y_king + 1]->get_piece() != nullptr && board[x_king + 1][y_king + 1]->get_piece_name() == "Pawn"
						&& board[x_king + 1][y_king + 1]->get_piece_colour() == "White") {
						std::cout << "Black King is in check by Black Pawn" << std::endl;
					}
				}

				// Now look in the horizontal and vertical directions
				for (int i = 0; i < 2; i++) {
					int n = i * 7;
					// Check the path from start to end 
					// If the path position is not clear find the piece at this position
					// These return the position of the piece that is in the way 
					test_piece = check_path_2(x_king, y_king, n, y_king);
					//std::cout << "Testing for stright piece (Horizontal) " << test_piece->get_name() << std::endl;
					//std::cout << n << "," << y_king << std::endl;
					// Horizontal check 
					if (test_piece->get_colour() != king_piece->get_colour()) {
						// If the colour of this piece is not the same as the kings colour

						if (test_piece->get_name() == "Queen" || test_piece->get_name() == "Rook") {
							// If the piece is a rook or a queen 
							std::cout << king_piece->get_colour() << " King is in check by " << test_piece->get_name() << std::endl;
						}
					}
					test_piece = check_path_2(x_king, y_king, x_king, n);
					//std::cout << "Testing for stright piece (Vertical) " << test_piece->get_name() << std::endl;
					//std::cout << x_king << "," << n << std::endl;
					if (test_piece->get_colour() != king_piece->get_colour()) {
						// If the colour of this piece is not the same as the kings colour
						if (test_piece->get_name() == "Queen" || test_piece->get_name() == "Rook") {
							std::cout << king_piece->get_colour() << " King is in check by " << test_piece->get_name() << std::endl;
						}
					}
				}

				// Check the diagonal for pieces
				// Set boundary conditions
				int x_diag_min;
				int y_diag_min;
				int x_diag_max;
				int y_diag_max;

				bool diag_check = false;

				for (int i = 0; i < 8; i++) {

					x_diag_min = x_king - i;
					y_diag_min = y_king - i;
					x_diag_max = x_king + i;
					y_diag_max = y_king + i; 

					// Check both minus values

					if (x_diag_min >= 0 && x_diag_min < 8 && y_diag_min >= 0 && y_diag_min < 8) {
						//std::cout << i <<  ": " << x_diag_min << ", " << y_diag_min << std::endl;
						test_piece = check_path_2(x_king, y_king, x_diag_min, y_diag_min);
						if (test_piece->get_colour() != king_piece->get_colour()) {
							//std::cout << "Agh 1: " << test_piece->get_name() << std::endl;
							if (test_piece->get_name() == "Queen" || test_piece->get_name() == "Bishop") {
								//std::cout << "King is in check by a " << test_piece->get_name() << std::endl;
								diag_check = true;
							}
						}
					}

					// Check both additional values

					if (x_diag_max >= 0 && x_diag_max < 8 && y_diag_max >= 0 && y_diag_max < 8) {
						//std::cout << i << ": " << x_diag_max << ", " << y_diag_max << std::endl;
						test_piece = check_path_2(x_king, y_king, x_diag_max, y_diag_max);
						if (test_piece->get_colour() != king_piece->get_colour()) {
							//std::cout << "Agh 2: " << test_piece->get_name() << std::endl;
							if (test_piece->get_name() == "Queen" || test_piece->get_name() == "Bishop") {
								//std::cout << "King is in check by a " << test_piece->get_name() << std::endl;
								diag_check = true;
							}
						}
					}

					// Check plus x, minus y

					if (x_diag_max >= 0 && x_diag_max < 8 && y_diag_min >= 0 && y_diag_min < 8) {
					
						test_piece = check_path_2(x_king, y_king, x_diag_max, y_diag_min);
						if (test_piece->get_colour() != king_piece->get_colour()) {
			
							if (test_piece->get_name() == "Queen" || test_piece->get_name() == "Bishop") {
								//std::cout << "King is in check by a " << test_piece->get_name() << std::endl;
								diag_check = true;
							}
						}
					}

					// Check minus x, plus y

					if (x_diag_min >= 0 && x_diag_min < 8 && y_diag_max >= 0 && y_diag_max < 8) {
						//std::cout << i << ": " << x_diag_min << ", " << y_diag_max << std::endl;
						test_piece = check_path_2(x_king, y_king, x_diag_min, y_diag_max);
						if (test_piece->get_colour() != king_piece->get_colour()) {
							//std::cout << "Agh 2: " << test_piece->get_name() << std::endl;
							if (test_piece->get_name() == "Queen" || test_piece->get_name() == "Bishop") {
								//std::cout << "King is in check by a " << test_piece->get_name() << std::endl;
								diag_check = true;
							}
						}
					}
				}
				if (diag_check == true) {
					std::cout << king_piece->get_colour() << " King is in check (diag) by a " << test_piece->get_name() << std::endl;
				}
				// Test for Knights
				int x_knight;
				int y_knight;

				for (int i = -2; i < 3; i++) {
					for (int j = -2; j < 3; j++) {
						x_knight = x_king + i;
						y_knight = y_king + j;

						if (abs(i) == 1 && abs(j) == 2 && x_knight >= 0 && x_knight < 8 && y_knight >= 0 && y_knight < 8
							|| abs(i) == 2 && abs(j) == 1 && x_knight >= 0 && x_knight < 8 && y_knight >= 0 && y_knight < 8) {

							if (board[x_knight][y_knight]->get_piece() != nullptr) {

								test_piece = board[x_knight][y_knight]->get_piece();

								if (test_piece->get_colour() != king_piece->get_colour()) {
									
									if (test_piece->get_name() == "Knight") {
										std::cout << king_piece->get_colour() << " King is in check (diag) by a " << test_piece->get_name() << std::endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

// ############################ Possible Moves for a piece ##############################################
