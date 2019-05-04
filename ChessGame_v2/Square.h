#ifndef SQUARE_H 
#define SQUARE_H
#include "Piece.h"
#include<string>

//
// Square class
//

// Class to create a single block on board and contain piece type
class Square {
// I will need to overload the ostream of square to output the symbol of the piece in the square
// Blank squares need to be considered too 
public:
	int x; int y;
	Piece *piece_name;
	Square() { piece_name = nullptr; }
	Square(int X, int Y); // NOTE: Create a blank square if there is no piece
	~Square() {};
	// Access function
	int get_x() { return x; }
	int get_y() { return y; }
	Piece* get_piece() const; 
	std::string get_piece_name() const;
	std::string get_piece_colour() const;
	void set_piece(Piece *piece);
	char display_square() const;
	// Clear the square
	void clear_square(); // A function to clear the square need to delete the piece if the piece is not null
	// Check the square in the path of a piece that will move to a new square
	bool check_occupation() const;
};
#endif
