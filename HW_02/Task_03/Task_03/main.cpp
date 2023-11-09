#include <iostream>
#include <mutex>
#include <thread>
#include <utility>

class Data {
private:
	std::recursive_mutex rm;
	int a;
public:
	Data();
	Data(int a): a(a){
		std::cout << "Constructor called...\n";
		//std::lock_guard lk(rm);
	};

	void lock() {
		std::lock_guard lk(rm);
	}
	void unlock() {
		std::cout << "Destructor...\n";
	}

	void lock_scoped(Data&other) {
		std::scoped_lock sl(rm, other.rm);
	}

	void lock_unique(Data& other) {
		std::unique_lock ul(other.rm);
		//other.lock_unique(?);
	}
	Data& operator=(const Data& other) = delete;

	
	void swap(Data& other) {
		a = other.a;
		//rm(other.rm);
	}

	~Data() {
		std::cout << "Destructor called...\n";
	}
};

void swap_01(Data& data1, Data& data2) {
	data1.lock();
	data2.lock();
	data1.swap(data2);
}

void swap_02(Data& data1, Data& data2) {
	data1.lock_scoped(data2);
	data1.swap(data2);
}

void swap_03(Data& data1, Data& data2) {
	data1.lock_unique(data2);
	data1.swap(data2);
}

int main() {
	Data d1(5);
	Data d2(10);
	//swap_01(d1, d2);
	//swap_02(d1, d2);
	swap_03(d1, d2);
	std::cout << "address of d1 " << &d1 << "\naddress of d2 " << &d2 << std::endl;
	return 0;
}