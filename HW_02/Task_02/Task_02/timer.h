#pragma once
#include <iostream>
#include <chrono>

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
		std::cout << _name << "\t\t" << elapsed() * 1000 << " ms" << std::endl;
	}
};
