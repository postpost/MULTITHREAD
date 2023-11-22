#pragma once
#include "line.h"
#include <vector>

class Sqr:public Line
{
public:
	Sqr(std::vector<Coordinate> sqr_coord);
	void shift(int m, int n);
	void scaleX(int a);
	void scaleY(int d);
	//void scaleZ(int e);
	void scale(int s);
	void calculate_sides() override;
};

