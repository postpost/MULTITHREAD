#pragma once
#include "shape.h"
#include <vector>

class Line:public Shape 
{
protected:
	int a, b, c;
	double square = 0;
	double volume = 0;
	struct Coordinate {
		int x_, y_;
		Coordinate(int x, int y) : x_(x), y_(y){};
	};
	std::vector <Coordinate> coord;
public:
	Line();
	Line(std::vector<Coordinate> line_coord) {};
	void calculate_sides() override;
	void shift(int m, int n);
	void scaleX(int a);
	void scaleY(int d);
	void scaleZ(int e);
	void scale(int s);
};
