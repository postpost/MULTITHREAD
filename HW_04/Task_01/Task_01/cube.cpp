#include "cube.h"

Cube::Cube(std::vector<Coordinate> cube_coord) 
{
	t = Type::cube;
	coord.assign(cube_coord.begin(), cube_coord.end());
	square = square = 2*(a * b + a * c + b * c);
	volume = a * b * c;
}


void Cube::shift(int m, int n, int k)
{
	for (auto& el : coord) {
		el.x_ += m;
		el.y_ += n;
		el.z_ += k;
	}
};

void Cube::scaleX(int a)
{
	for (auto& el : coord) {
		el.x_ *= a;
	}
};
void Cube::scaleY(int d) {
	for (auto& el : coord) {
		el.y_ *= d;
	}
};
void Cube::scaleZ(int e)
{
	for (auto& el : coord) {
		el.z_ *= e;
	}
};
void Cube::scale(int s) {
	for (auto& el : coord) {
		el.x_ /= s;
		el.y_ /= s;
		el.z_ /= s;
	}
};
void Cube::calculate_sides()
{
	std::vector<Coordinate>::iterator it = coord.begin();
	for (; it != coord.end(); ++it) {
		for (auto itr = it + 1; itr != coord.end(); ++itr) {
			a = abs((*it).x_ - (*itr).x_);
			b = abs((*it).y_ - (*itr).y_);
			c = abs((*it).z_ - (*itr).z_);
		}
	}
}
