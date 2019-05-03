#ifndef PLAYER_H 
#define PLAYER_H
#include<string>
class Player {
public:
	std::string colour;
	Player() {};
	Player(std::string colour) { this->colour = colour; };
	~Player() {}
	std::string get_player() { return colour; }
};
#endif
