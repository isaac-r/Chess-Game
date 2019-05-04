#include "Square.h"
#include<iostream>
#include<string>
#include "Board.h"

Square::Square(int X, int Y) {
	// Need to assign the x and y value of the square to position it on the board
	// Then need to assign a piece to this sqaure
		//std::cout << "Parameterized Square constructor called" << std::endl;
	piece_name = nullptr;
	x = X;
	y = Y;
	// Need to define an empty square
	// Function "check_occupation(square)" returns boolean for sqaure occupied or not
}
Piece* Square::get_piece() const {
	if (x >= 0 && x < 8 && y >= 0 && y < 8) {
		return piece_name;
	}
	else { return nullptr; }
}
std::string Square::get_piece_name() const {
	return piece_name->get_name();
}
std::string Square::get_piece_colour() const {
	return piece_name->get_colour();
}
void Square::set_piece(Piece *piece) {
	piece_name = piece;
}
// Function to find the symbol of a piece in a square
 char Square::display_square() const {
	if (this->check_occupation() == true) {
		//std::cout << piece_name->get_symbol();
		return piece_name->get_symbol();
	}
	else {
		return ' ';
	}
}
bool Square::check_occupation() const {
	if (this->get_piece() == nullptr) {
		return false;
	}
	else {
		return true;
	}
}

void Square::clear_square() {
	piece_name = nullptr;
}
