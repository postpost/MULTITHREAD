#include <iostream>
#include <mutex>
#include <thread>
#include <utility>

class Data {
private:
	int a_;
	std::string str_;
public:
	std::mutex m;
	Data();
	Data(int a, std::string str): a_(a), str_(str){
		std::cout << "Constructor called...\n";
		//std::lock_guard lk(rm);
	};
	Data& operator=(const Data& other) = delete;
	void swap(Data& other) {
		std::swap(this->a_, other.a_);
		std::swap(this->str_, other.str_);
	}

	void print_data() {
		std::cout << "a=" << a_ << "\t" << "string=" << str_ << std::endl;
	}
	~Data() {
		std::cout << "Destructor called...\n";
	}
};

void lock_1(Data& d1, Data& d2) {
	std::lock(d1.m, d2.m);
	std::lock_guard lk1(d1.m, std::adopt_lock);
	std::lock_guard lk2(d2.m, std::adopt_lock);
	d1.swap(d2);
	std::cout << "Data 1 contains\n";
	d1.print_data();
	std::cout << "Data 2 contains\n";
	d2.print_data();
}

void lock_2(Data& d1, Data& d2) {
	std::lock(d1.m, d2.m);
	std::unique_lock uk1(d1.m, std::adopt_lock);
	std::unique_lock uk2(d2.m, std::adopt_lock);
	std::cout << "Data 1 contains\n";
	d1.print_data();
	std::cout << "Data 2 contains\n";
	d2.print_data();
}

void lock_3(Data& d1, Data& d2) {
	std::scoped_lock(d1.m, d2.m);
	std::cout << "Data 1 contains\n";
	d1.print_data();
	std::cout << "Data 2 contains\n";
	d2.print_data();
}

int main() {
	Data d1(5, "mutex");
	Data d2(10, "async");
	lock_1(d1, d2);
	lock_2(d1, d2);
	lock_3(d1, d2);
	//std::cout << "address of d1 " << &d1 << "\naddress of d2 " << &d2 << std::endl;
	return 0;
}