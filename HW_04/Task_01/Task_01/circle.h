#pragma once
#include "shape.h"

class Circle:public Shape
{
protected:
	int x_, y_;
	double square;
	double volume;
	double radius;
public:
	Circle();
	Circle(int x, int y, double R){};
};

