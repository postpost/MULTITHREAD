#pragma once
#include "circle.h"

class Cylinder:public Circle
{
private:
	double height;
public:
	Cylinder(int x, int y, double R, double H);
};

