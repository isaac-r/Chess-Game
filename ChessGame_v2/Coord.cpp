#include "Coord.h"
#include<string>
#include<iostream>
Coord::Coord(std::string position) {
	// overload the istream function to take the user input position 
	// Call constructor in the piece class to assign possition to the piece
	// Check the position is within the board limits
	int x_int = -1;
	int y_int = -1;
	in_position = position;

	do {
		std::cin >> position;
		char x_input = position[0];
		char y_input = position[1];
		// Convert the characters into integers
		if (x_input == tolower('A')) {
			x_int = 0;
		}
		else if (x_input == tolower('B')) {
			x_int = 1;
		}
		else if (x_input == tolower('C')) {
			x_int = 2;
		}
		else if (x_input == tolower('D')) {
			x_int = 3;
		}
		else if (x_input == tolower('E')) {
			x_int = 4;
		}
		else if (x_input == tolower('F')) {
			x_int = 5;
		}
		else if (x_input == tolower('G')) {
			x_int = 6;
		}
		else if (x_input == tolower('H')) {
			x_int = 7;
		}
		//else if (position == "moves") {
			// Show the moves to the player for the piece on the selected square 
			//std::cout << "Asking for moves" << std::endl;
			// Need to check this in the range checker
			//exit(1);
		//}
		else if (position == "quit") {
			// Show the moves to the player for the piece on the selected square 
			std::cout << "You gave up?!?" << std::endl;
			exit(1);
		}
		else {
			x_int = -1;
		}

		y_int = y_input - '0' - 1;

		if (x_int < 0 || x_int > 7 || y_int < 0 || y_int > 7) {
			//if (position != "moves") {
				std::cout << "Piece is out of range please try again: " << std::endl;
			//}
		}

	}// while (x_int < 0 && position != "moves" || x_int > 7 && position != "moves" || 
		//y_int < 0 && position != "moves" || y_int > 7 && position != "moves");
	while (x_int < 0 || x_int > 7  || y_int < 0  || y_int > 7);

	x = x_int;
	y = y_int;

}

bool Coord::operator!=(const Coord &position) {
	if (this->get_x() != position.get_x() && this->get_y() != position.get_y()) {
		return true;
	}
	else {
		return false;
	}
}