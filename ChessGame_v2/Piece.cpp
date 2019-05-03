#include "Piece.h"
#include<iostream>
#include<string>
#include "Board.h"
#include "Square.h"

Pawn::Pawn(std::string colour) {
	name = "Pawn";
	 this->colour = colour;
	if (colour == "White") {
		symbol = 'P';
	}
	else if (colour == "Black") {
		symbol = 'p';
	}
}

Rook::Rook(std::string colour) {
	name = "Rook";
	this->colour = colour;
	if (colour == "White") {
		symbol = 'R';
	}
	else if (colour == "Black") {
		symbol = 'r';
	}
}

Knight::Knight(std::string colour) {
	name = "Knight";
	this->colour = colour;
	if (colour == "White") {
		symbol = 'N';
	}
	else if (colour == "Black") {
		symbol = 'n';
	}
}

Bishop::Bishop(std::string colour) {
	name = "Bishop";
	this->colour = colour;
	if (colour == "White") {
		symbol = 'B';
	}
	else if (colour == "Black") {
		symbol = 'b';
	}
}

Queen::Queen(std::string colour) {
	name = "Queen";
	this->colour = colour;
	if (colour == "White") {
		symbol = 'Q';
	}
	else if (colour == "Black") {
		symbol = 'q';
	}
}

King::King(std::string colour) {
	name = "King";
	this->colour = colour;
	if (colour == "White") {
		symbol = 'K';
	}
	else if (colour == "Black") {
		symbol = 'k';
	}
}

//
// Functions for moving pieces
//

bool Pawn::move_piece(std::string colour, int x_1, int y_1, int x_2, int y_2) {
	int dx = x_2 - x_1;
	int dy = y_2 - y_1;
	// Also need to check if the pawn is in its start position (or hasn't moved yet)
	// Move counter for each piece 
	if (colour == "White" && dy == -1 && dx == 0 || colour == "Black" && dy == 1 && dx == 0) {
		std::cout << "Temp move allowed for " << colour << " pawn" << std::endl;
		move_counter++;
		std::cout << "Number of moves = " << move_counter << std::endl;
		return valid_move = true;
	}
	else if (move_counter == 0 && colour == "White" && dy == -2 && dx == 0 || 
		move_counter == 0 && colour == "Black" && dy == 2 && dx == 0) {

		std::cout << "Temp move allowed for " << colour << " pawn" << std::endl;
		move_counter++;
		std::cout << "Number of moves = " << move_counter << std::endl;
		return valid_move = true;
	}
	// Specialised pawn movement (counter or position checker) 
	// Diagonal movements allowed forwards (protect this later)
	else {
		std::cout << "Move not allowed for " << colour << " pawn!" << std::endl;
		return valid_move = false;
	}
}

bool Piece::move_pawn(std::string colour_1, std::string colour_2, int x_1, int y_1, int x_2, int y_2) {
	int dx = x_2 - x_1;
	int dy = y_2 - y_1;
	if (colour_1 != colour_2) {
		std::cout << "Special pawn move " << std::endl;
		if (colour_1 == "Black" && dy == 1 && abs(dx) == 1) {
			std::cout << "Temp move allowed for " << colour << " pawn" << std::endl;
			return valid_move = true;
		}
		else if (colour_1 == "White" && dy == -1 && abs(dx) == 1) {
			std::cout << "Temp move allowed for " << colour << " pawn" << std::endl;
			return valid_move = true;
		}
		else {
			std::cout << "Move not allowed for " << colour << " pawn!" << std::endl;
			return valid_move = false;
		}
	}
	else {
		return move_piece(colour_1, x_1, y_1, x_2, y_2);
	}
}

bool Rook::move_piece(std::string colour, int x_1, int y_1, int x_2, int y_2) {
	int dx = x_2 - x_1;
	int dy = y_2 - y_1;
	if (dy != 0 && dx == 0 || dy == 0 && dx != 0) {
		std::cout << "Temp move allowed for " << colour << " rook" << std::endl;
		return valid_move = true;
	}
	else {
		std::cout << "Move not allowed for " << colour << " rook!" << std::endl;
		return valid_move = false;
	}
}

bool Knight::move_piece(std::string colour, int x_1, int y_1, int x_2, int y_2) {
	int dx = x_2 - x_1;
	int dy = y_2 - y_1;
	if (abs(dy) == 2 && abs(dx) == 1 || abs(dy) == 1 && abs(dx) == 2) {
		std::cout << "Temp move allowed for " << colour << " knight" << std::endl;
		return valid_move = true;
	}
	else {
		std::cout << dx << " in x " << dy << " in y" << std::endl;
		std::cout << "Move not allowed for " << colour << " knight!" << std::endl;
		return valid_move = false;
	}
}

bool Bishop::move_piece(std::string colour, int x_1, int y_1, int x_2, int y_2) {
	int dx = x_2 - x_1;
	int dy = y_2 - y_1;
	if (abs(dy) == abs(dx)) {
		std::cout << "Temp move allowed for " << colour << " bishop" << std::endl;
		return valid_move = true;
	}
	else {
		std::cout << "Move not allowed for " << colour << " bishop!" << std::endl;
		return valid_move = false;
	}
}

bool Queen::move_piece(std::string colour, int x_1, int y_1, int x_2, int y_2) {
	int dx = x_2 - x_1;
	int dy = y_2 - y_1;
	if (dy != 0 && dx == 0 || dy == 0 && dx != 0 || abs(dy) == abs(dx)) {
		std::cout << "Temp move allowed for " << colour << " queen" << std::endl;
		return valid_move = true;
	}
	else {
		std::cout << "Move not allowed for " << colour << " queen!" << std::endl;
		return valid_move = false;
	}
}

bool King::move_piece(std::string colour, int x_1, int y_1, int x_2, int y_2) {
	int dx = x_2 - x_1;
	int dy = y_2 - y_1;
	if (abs(dy) == 1 && dx == 0 || dy == 1 && abs(dx) == 1) {
		std::cout << "Temp move allowed for " << colour << " king" << std::endl;
		return valid_move = true;
	}
	else if (abs(dy) == abs(dx)) {
		std::cout << "Temp move allowed for " << colour << " king" << std::endl;
		return valid_move = true;
	}
	else {
		std::cout << "Move not allowed for " << colour << " king!" << std::endl;
		return valid_move = false;
	}
}