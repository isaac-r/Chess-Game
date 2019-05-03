#ifndef GAME_H 
#define GAME_H
#include "Player.h"
#include "Board.h"
class Game {
public:
	Player player_1, player_2;
	std::string name_1, name_2;
	Board board;
	Game() {};
	Game(Player white, Player black, Board game_board);
	~Game() {}
	bool is_game_over(Board board);
};
#endif