#define _USE_MATH_DEFINES
#include "cylinder.h"
#include<cmath>

Cylinder::Cylinder(int x, int y, double R, double H)
{
	t = Type::cylinder;
	x_ = x;
	y_ = y;
	radius = R;
	height = H;
	square = M_PI * 2 * std::pow(R, 3)* height;
	volume = M_PI * std::pow(R, 2)* height;
};
