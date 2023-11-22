#include "sqr.h"

Sqr::Sqr(std::vector<Coordinate> sqr_coord) 
{
	t = Type::sqr;
	coord.assign(sqr_coord.begin(), sqr_coord.end());
	square = a * b;
};


void Sqr::shift(int m, int n)
{
	for (auto& el : coord) {
		el.x_ += m;
		el.y_ += n;
	}
};

void Sqr::scaleX(int a)
{
	for (auto& el : coord) {
		el.x_ *= a;
	}
};
void Sqr::scaleY(int d) {
	for (auto& el : coord) {
		el.y_ *= d;
	}
};
//void Sqr::scaleZ(int e)
//{
//	for (auto& el : coord) {
//		el.z_ *= e;
//	}
//};
void Sqr::scale(int s) {
	for (auto& el : coord) {
		el.x_ /= s;
		el.y_ /= s;
	}
};

void Sqr::calculate_sides()
{
	std::vector<Coordinate>::iterator it = coord.begin();
	for (; it != coord.end(); ++it) {
		for (auto itr = it + 1; itr != coord.end(); ++itr) {
			a = abs((*it).x_ - (*itr).x_);
			b = abs((*it).y_ - (*itr).y_);
			//c = abs((*it).z_ - (*itr).z_);
		}
	}
}
