#include "Square.h"
#include "Player.h"
#include "Board.h"
#include "Piece.h"
#include "Game.h"
#include<iostream>
// File to run the main program 

int main()
{

	std::cout << "Welcome to Chess!" << std::endl;
	Player player_1;
	Player player_2;
	Board board;
	Game begin(player_1, player_2, board);

	return 0;
}