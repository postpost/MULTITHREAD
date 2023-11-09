#include <iostream>
#include <thread>
#include <future>

void sort(int* array, int size, std::promise<int*> prom) {
	int smallest = 0;
	for (int start = 0; start < size; ++start) {
		smallest = start;
		for (int current = smallest + 1; current < size; ++current) {
			if (array[current] < array[smallest]) {
				smallest = current;
			}
		}
		std::swap(array[start], array[smallest]);
	}
	//prom.set_value(array[i]);
	prom.set_value(array);
}

void print_array(int* array, const int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

//template <typename T>
void fill_arr(int* array, const int size) {
	for (int i = 0; i < size; ++i) {
		array[i] = std::rand() % 10;
	}
}

int sum(int a, int b) {
	return a + b;
}

int main() {
	int size = 10;
	int* array = new int[size];
	fill_arr(array, size);
	print_array(array, size);

	// async
	std::promise<int*> prom;
	std::future<int*> f1 = prom.get_future(); //connection
	auto f2 = std::async(std::launch::async, sort, std::ref(array), size, std::move(prom));
	array = f1.get();
	print_array(array, size);
	delete[] array;
	return 0;
}