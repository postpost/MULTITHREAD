#include "line.h"

Line::Line(std::vector<Coordinate> line_coord)
{
	t = Type::line;
	coord.assign(line_coord.begin(), line_coord.end());
};

void Line::shift(int m, int n)
{
	for (auto& el : coord) {
		el.x_ += m;
		el.y_ += n;
	}
};

void Line::scaleX(int a) 
{
	for (auto& el : coord) {
		el.x_ *= a;
	}
};
void Line::scaleY(int d) {
	for (auto& el : coord) {
		el.y_ *= d;
	}
};
//void Line::scaleZ(int e)
//{
//	for (auto& el : coord) {
//		el.z_ *= e;
//	}
//};
void Line::scale(int s) {
	for (auto& el : coord) {
		el.x_ /= s;
		el.y_ /= s;
	}
};

void Line::calculate_sides() 
{
	std::vector<Coordinate>::iterator it = coord.begin();
	for (; it != coord.end(); ++it) {
		for (auto itr = it + 1; itr != coord.end(); ++itr) {
			a = abs((*it).x_ - (*itr).x_);
			b = abs((*it).y_ - (*itr).y_);
		}
	}
}