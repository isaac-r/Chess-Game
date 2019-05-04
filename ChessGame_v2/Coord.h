#ifndef COORD_H 
#define COORD_H
#include<string>

class Coord {
public:
	int x, y;
	std::string in_position;
	Coord() {};
	Coord(std::string position);
	Coord(int X, int Y) { x = X, y = Y; }
	~Coord() {};
	int get_x() const { return x; };
	int get_y() const { return y; };
	std::string get_input() { return in_position; }
	bool operator!=(const Coord &position);
};

#endif
