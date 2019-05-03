#ifndef PIECE_H 
#define PIECE_H
#include<string>
#include<iostream>

//
// Piece Class
//

class Piece {
public:
	// Piece will need to have position, name, colour (from value)
	std::string name, colour; // To define the type of piece and its colour
	char symbol; // To provide a symbol for output of the piece
	int x, y;
	bool valid_move;
	int move_counter;
	// Define constructor and destructor for piece
	Piece() {}
	~Piece() { std::cout << "Piece Destructor called" << std::endl; }
	// Access functions
	char get_symbol() const { return symbol; }
	std::string get_name() const { return name; }
	std::string get_colour() const { return colour; }
	//static int get_move_count() { return move_counter; }
	// Member functions
	bool move_pawn(std::string colour_1, std::string colour_2, int x_1, int y_1, int x_2, int y_2);
	// Move piece virtual function
	virtual bool move_piece(std::string colour, int x_1, int y_1, int x_2, int y_2) = 0;
};

class Pawn : public Piece {
public:
	int move_counter = 0;
	Pawn() {}
	Pawn(std::string colour);
	~Pawn() {}
	bool move_piece(std::string colour, int x_1, int y_1, int x_2, int y_2);
};

class Rook : public Piece {
public:
	int move_counter = 0;
	Rook() {}
	Rook(std::string colour);
	~Rook() {}
	bool move_piece(std::string colour, int x_1, int y_1, int x_2, int y_2);
};

class Knight : public Piece {
public:
	int move_counter = 0;
	Knight() {}
	Knight(std::string colour);
	~Knight() {}
	bool move_piece(std::string colour, int x_1, int y_1, int x_2, int y_2);
};

class Bishop : public Piece {
public:
	int move_counter = 0;
	Bishop() {}
	Bishop(std::string colour);
	~Bishop() {}
	bool move_piece(std::string colour, int x_1, int y_1, int x_2, int y_2);
};

class Queen : public Piece {
public:
	int move_counter = 0;
	Queen() {}
	Queen(std::string colour);
	~Queen() {}
	bool move_piece(std::string colour, int x_1, int y_1, int x_2, int y_2);
};

class King : public Piece {
public:
	int move_counter = 0;
	King() {}
	King(std::string colour);
	~King() {}
	bool move_piece(std::string colour, int x_1, int y_1, int x_2, int y_2);
};
#endif