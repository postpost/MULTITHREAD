#pragma once
#include "line.h"
#include <vector>

class Cube:public Line
{
private:
	struct Coordinate {
		int x_, y_, z_;
		Coordinate(int x, int y, int z) : x_(x), y_(y), z_(z) {};
	};
	std::vector<Coordinate> coord;
public:
	Cube(std::vector<Coordinate> cube_coord) {};
	void shift(int m, int n, int k);
	void scaleX(int a);
	void scaleY(int d);
	void scaleZ(int e);
	void scale(int s);
	void calculate_sides() override;
};

