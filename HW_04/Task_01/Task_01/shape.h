#pragma once
#include<string>
class Shape
{
protected:
	enum Type { line = 0, sqr = 1, cube = 2, circle = 3, cylinder = 4 };
	Type t;
public:
	Shape() = default;
	int getType();
	virtual void calculate_sides();
};
