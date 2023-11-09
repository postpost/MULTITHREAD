#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std::chrono_literals;
std::once_flag flag;
//������ ����� ��������� �������
//��� � ������� �� ���������� � �������� �������� � ����������� ��� �� 1
//������������ ���������� �������� ������ ���� �����������������

//thread_local int - for each thread separately
int count = 0; //������� ��������

void print_header() {
	std::cout << "Client count is: " << std::endl;
}

void client_thread(int max) {
	std::this_thread::sleep_for(1000ms);
	std::call_once(flag, print_header);
	for (int i = 0; i < max; ++i) {
		count++;
		std::cout << count << " ";
	}
	std::cout << std::endl;
}

//������ ����� ��������� �������������
//��� � 2 ������� �� ���������� � �������� �������� � ��������� ��� �� 1
//������������� �������� �� ���������� �������

void operator_thread(int max) {
	std::this_thread::sleep_for(2000ms);
	std::call_once(flag, print_header);
	for (int i = 0; i < max; ++i) {
		count--;
		std::cout << count << " ";
	}
	std::cout << std::endl;
}


int main() {
	std::cout << "Thread" << std::endl;
	int max = 10;
	std::thread t1(client_thread, max);
	std::thread t2(operator_thread, max);
	t1.join();
	std::cout << "Thread_1: total count = " << count << std::endl;
	t2.join();
	std::cout << "Thread_2: total count = " << count << std::endl;

	return 0;
}