#pragma once
#include<string>
#include <vector>
class Shape
{
private:
	struct Coordinate {
		int x_, y_, z_;
		Coordinate(int x, int y , int z = 0) : x_(x), y_(y), z_(z){};
	};
	int a, b, c;
	
public:
	enum Type { line = 0, sqr = 1, cube = 2, circle = 3, cylinder = 4 };
	Type t;
	std::vector<Coordinate> coord;
	Shape() = default;
	Shape(int type, std::vector<Coordinate> vo);
	Shape(int type, int x, int y, double R, double H = 0);
	int getType();
	double volume;
	double square;
	double height;
	double radius;
	void fill_coordinates(int type, std::vector<Coordinate> vc);
	void shape_sides();
	void calculate_sides();
	double calculate_sqr(Type t, int a, int b, int c);
	double calculate_vol(Type t, int a, int b, int c);
	double calc_s_circle(double R);
	double calc_s_cylinder(double R, double H);
	double calc_sqr_circle(Type t, double R, double H = 0);
	double calc_vol_cylinder(Type t, double R, double H = 0);
};
