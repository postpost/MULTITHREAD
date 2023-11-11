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

void DrawProgressBar(int i) {
	Timer timer;
	system("color 0A");
	//initialize char to print bar
	char a = 176, b = 219; //221
	int x = std::rand() % 10000;
	timer.start();
	for (int k = 0; k < 10; ++k) {
		std::this_thread::sleep_for(std::chrono::milliseconds(x));
		std::unique_lock lk(m);
		consol_parameter::SetPosition(30+k, 2+i);
		//lk.unlock();
		std::cout << b;
		Sleep(200);
	}
	std::this_thread::sleep_for(500ms);
	std::unique_lock lk(m);
	consol_parameter::SetPosition(30, 2 + i);
	//lk.unlock();
	timer.print();
}
void LoadBar(int i, int N) {
	//сюда заходят сразу все 4 потока
	std::call_once(once, print_headers);
	std::unique_lock lk(m);	
	std::cout << i << "\t\t" << std::this_thread::get_id() << "\n";
	lk.unlock();
	DrawProgressBar(i);
	
}

void task() {
	std::vector <std::thread> vt;
	int N = 5;
	for (int i = 0; i < N; ++i) {
		vt.push_back(std::thread(LoadBar, i, N));
	}
	for (auto& el : vt) {
		el.join();
		//consol_parameter::SetPosition(0, 6);
	}
}


int main() {
	task();
	return 0;
}