#pragma once
#include <iostream>
#include <chrono>
#include <Windows.h>

class Timer {
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	std::string _name;
	std::chrono::time_point<clock_t> begin;

	double elapsed() const {
		return std::chrono::duration_cast<second_t>(clock_t::now() - begin).count();
	}
public:
	Timer() :begin(clock_t::now()){}; //store begin time
	Timer(std::string name) :_name(name), begin(clock_t::now()) {};

	void start(std::string name="") {
		this->_name = name;
		begin = clock_t::now();
	}
	void print() const {
		std::cout << _name << "\t\t\t\t" << elapsed() * 1000 << " ms" << std::endl;
	}
};

class consol_parameter
{
public:
	static void SetColor(int text, int background)
	{
		SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
	}
	static void SetPosition(int x, int y)
	{
		COORD point;
		point.X = x;
		point.Y = y;
		SetConsoleCursorPosition(hStdOut, point);
	}
private:
	static HANDLE hStdOut;
};
HANDLE consol_parameter::hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

