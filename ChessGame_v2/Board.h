#ifndef BOARD_H 
#define BOARD_H
#include "Square.h"
#include<iostream>
#include "Player.h"
#include "Coord.h"

//
// Board class
//

class Board {
	// Create a board of sqaures and assign pieces to those squares
public:
	// Create the board and assign zero to all values on it
	Square *board[8][8]; // 2D Array for the board points to a square
	Board();
	~Board() { std::cout << "Board destructor called" << std::endl; }
	// Define functions for the board class
	void create();
	Square &operator()(int m, int n) { return *board[m][n]; }
	void show();
	void move(Player player);
	bool check_path(int x_i, int y_i, int x_f, int y_f);
	Piece* check_path_2(int x_i, int y_i, int x_f, int y_f);
	void is_king_in_check();
};

#endif