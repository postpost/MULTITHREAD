#include <iostream>
#include <thread>
#include <Windows.h>
#include <chrono>
#include <mutex>
#include <vector>
#include "timer.h"

using namespace std::chrono_literals;
std::mutex m;
//std::atomic_flag flag = ATOMIC_FLAG_INIT;
//std::condition_variable data_cond;
std::once_flag once;

void print_headers() {
	std::cout << "#\t\tId\t\tProgress Bar\t\tTime\n\n";
}

void DrawProgressBar() {
	system("color 0A");
	//initialize char to print bar
	char a = 176, b = 219; //221
	for (int i = 0; i < 10; ++i) {
		std::cout << a;
	}
	std::cout << "\r";
	for (int i = 0; i < 10; ++i) {
		std::cout << i;
		Sleep(500);
	}
	std::cout << std::endl;
}
void LoadBar(int i, int N) {
	//сюда заходят сразу все 4 потока
	std::call_once(once, print_headers);
	Timer timer;
	std::unique_lock lk(m);	
	std::cout << i << "\t\t" << std::this_thread::get_id() << "\n";
	lk.unlock();
	timer.start();
	//...to do
	std::this_thread::sleep_for(2000ms);
	DrawProgressBar();
	timer.print();
}

void task() {
	std::vector <std::thread> vt;
	int N = 5;
	for (int i = 0; i < N; ++i) {
		vt.push_back(std::thread(LoadBar, i, N));
	}
	for (auto& el : vt) {
		el.join();
		consol_parameter::SetPosition(0, 6);
	}
}


int main() {
	task();
	return 0;
}