#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
#include <Windows.h>

using namespace std::chrono_literals;
std::once_flag flag;
std::atomic_flag atomic_flag = ATOMIC_FLAG_INIT;
std::mutex m;
//Первый поток имитирует клиента
//раз в секунду он обращается к счётчику клиентов и увеличивает его на 1
//Максимальное количество клиентов должно быть параметризировано

//thread_local int - for each thread separately
std::atomic<int> count = 0; //счётчик клиентов

void print_header() {
	std::cout << "Client count is: " << std::endl;
}

void client_thread(int max) {
	std::lock_guard lk(m);
	atomic_flag.test_and_set();
	//std::this_thread::sleep_for(100ms);
	while (atomic_flag.test_and_set()) {
		std::cout << "Client in the queuee...\n";
		//std::cout << "Client flag after = " << atomic_flag.test_and_set() << std::endl;
		std::call_once(flag, print_header);
		for (int i = 0; i < max; ++i) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			count++;
			std::cout << count << " ";
			atomic_flag.clear();
			//lk.unlock();
			std::this_thread::sleep_for(1000ms);
			//lk.lock();
		}

	}
	std::cout << std::endl;
}

//Второй поток имитирует операциониста
//раз в 2 секунды он обращается к счётчику клиентов и уменьшает его на 1
//«Операционист» работает до последнего клиента

void operator_thread(int max) {
	std::unique_lock lk(m, std::defer_lock);
	std::call_once(flag, print_header);
	//std::cout << "Opeartor: " << atomic_flag.test_and_set() << std::endl;
	while (atomic_flag.test_and_set()) {
		
		std::cout << "Operator is working...\n";
		//std::cout << "Operator flag after = " << atomic_flag.test_and_set() << std::endl;
		for (int i = 0; i < max; ++i) {
			std::this_thread::sleep_for(2000ms);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			count--;
			std::cout << count << " ";
			atomic_flag.clear();
		}
		
	}
	
	std::cout << std::endl;
}


int main() {
	int max = 10;
	std::thread t1(client_thread, max);
	std::thread t2(operator_thread, max);
	t1.join();
	t2.join();
	
	return 0;
}