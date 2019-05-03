#ifndef COORD_H 
#define COORD_H
#include<string>

class Coord {
public:
	int x, y;
	Coord() {};
	Coord(std::string position);
	Coord(int X, int Y) { x = X, y = Y; }
	~Coord() {};
	int get_x() const { return x; };
	int get_y() const { return y; };
	bool operator!=(const Coord &position);
};

#endif
