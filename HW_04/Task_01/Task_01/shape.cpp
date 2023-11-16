#define _USE_MATH_DEFINES
#include"shape.h"
#include<cmath>

Shape::Shape(int type, std::vector<Coordinate> vo) {
	t = static_cast<Type>(type);
	//fill coordinates
	coord.assign(vo.begin(), vo.end());
	//shape sides
	calculate_sides();
	//calculate square
	calculate_sqr(t, a, b, c);
	//calculate volume
	calculate_vol(t, a, b, c);
}

Shape::Shape(int type, int x, int y, double R, double H)
{
	Type t = static_cast<Type>(type);
	coord.push_back(Coordinate(x, y));
	radius = R;
	if (Type::cylinder) {
		height = H;
	}
	// считаем площадь фигуры
	calc_sqr_circle(t, R, H);
	// считаем объем фигуры
	calc_vol_cylinder(t, R, H);
}

void Shape::calculate_sides() {
	std::vector<Coordinate>::iterator it = coord.begin();
	for (; it != coord.end(); ++it) {
		for (auto itr = it + 1; itr != coord.end(); ++itr) {
			a = abs((*it).x_ - (*itr).x_);
			b = abs((*it).y_ - (*itr).y_);
			c = abs((*it).z_ - (*itr).z_);
		}
	}
}

double Shape::calculate_sqr(Type t,int a, int b, int c) {
	switch (t)
	{
	case Type::line:
		square = 0;
		break;
	case Type::sqr:
		square = a * b;
		break;
	case Type::cube:
		square = 2 * (a * b + a * c + b * c);
		break;
	default:
		break;
	}
	return square;
};

double Shape::calculate_vol(Type t, int a, int b, int c) {
	if (t == Type::cube)
		volume = a * b * c;
	else
		volume = 0;
	return volume;
};

double Shape::calc_s_circle(double R) {
	square = M_PI * std::pow(R,2);
	return square;
};
double Shape::calc_s_cylinder(double R, double H) {
	square = M_PI * std::pow(R, 2) + 2 * R * height;
	return square;
};

double Shape::calc_sqr_circle(Type t,double R, double H) {
	switch (t)
	{
	case Type::circle:
		square = calc_s_circle(R);
		break;
	case Type::cylinder:
		square = calc_s_cylinder(R, H);
		break;
	default:
		break;
	}
	return square;
}
double Shape::calc_vol_cylinder(Type t,double R, double H) {
	if (t== Type::cylinder)
		volume = M_PI * std::pow(R,2) * height;
	else if (t == Type::circle)
		volume = 0;
	return volume;
};

int Shape::getType() {
	return t;
};