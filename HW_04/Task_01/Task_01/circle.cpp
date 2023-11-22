#define _USE_MATH_DEFINES
#include "circle.h"
#include<cmath>

Circle::Circle(int x, int y, double R):x_(x), y_(y), radius(R), volume(0)
{
	t = Type::circle;
	square = M_PI * std::pow(R,2);
};
