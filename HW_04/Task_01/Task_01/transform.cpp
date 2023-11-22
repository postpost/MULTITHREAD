#include "transform.h"

transform::transform(const Shape& sh)
{
	shape = sh;
}

Shape transform::shift(int m, int n, int k)
{
	if (shape.getType() == Shape::Type::cube) {
		for (auto& el : shape.coord) {
			el.x_ += m;
			el.y_ += n;
			el.z_ += k;
		}
	}
	else 
	{
		for (auto& el : shape.coord) {
			el.x_ += m;
			el.y_ += n;
		}
	}
	return shape;
}

Shape transform::scaleX(int a)
{
	for (auto& el : shape.coord) {
		el.x_ *= a;
	}
	return shape;
}

Shape transform::scaleY(int d)
{
	for (auto& el : shape.coord) {
		el.y_ *= d;
	}
	return shape;
}

Shape transform::scaleZ(int e)
{
	for (auto& el : shape.coord) {
		el.z_ *= e;
	}
	return shape;
}

Shape transform::scale(int s)
{
	if (shape.getType() == Shape::Type::cube) {
		for (auto& el : shape.coord) {
			el.x_ /= s;
			el.y_ /= s;
			el.z_ /= s;
		}
	}
	else {
		for (auto& el : shape.coord) {
			el.x_ /= s;
			el.y_ /= s;
		}
	}
	
	return shape;
}