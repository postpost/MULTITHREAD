#include <iostream>
#include <thread>
#include <future>

int find_min(int* array, int smallest, int size, std::promise<int>& prom) {
	//асинхронно запускается функция поиска минимума, который возвращается через std::future
	for (int current = smallest + 1; current < size; ++current) {
		if (array[current] < array[smallest]) {
			smallest = current;
		}
	}
	//prom.set_value(smallest);
	return smallest;
}

void sort(int* array, int size, std::promise<int>& prom) {
	int smallest = 0;
	for (int start = 0; start < size; ++start) {
		smallest = start;
		std::future ft = std::async(find_min, array, smallest,size, std::ref(prom));
		smallest = ft.get();
		std::swap(array[start], array[smallest]);
	}
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

int main() {
	int size = 10;
	int* array = new int[size];
	fill_arr(array, size);
	print_array(array, size);

	// async
	std::promise<int> prom;
	std::future<int> f_prom = prom.get_future(); //connection
	sort(array, size, prom);
	print_array(array, size);
	delete[] array;
	return 0;
}