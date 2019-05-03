#ifndef PLAYER_H 
#define PLAYER_H
#include<string>
class Player {
public:
	std::string colour, name;
	Player() {};
	Player(std::string colour, std::string name) { this->colour = colour; this->name = name; }
	~Player() {}
	std::string get_player_colour() { return colour; }
	std::string get_player_name() { return name; }
};
#endif
