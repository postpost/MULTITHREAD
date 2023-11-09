#include <iostream>
#include <vector>
#include <iterator>
#include <random>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std::chrono_literals;

//method to generate random numbers 
std::vector<int> randomize_v(size_t size) {
	std::vector<int> v(size);
	std::random_device rand;
	std::generate(v.begin(), v.end(), [&]() {
		return rand()%10;
		});
	return v;
}

//print vector
void print_v(std::vector<int>& v) {
	for (auto& el : v) {
		std::cout << el << " ";
	}
	std::cout << std::endl;
}

void sum_vector(const std::vector<int>& v1, const std::vector<int> v2) {
	auto start = std::chrono::steady_clock::now();
	std::vector<int> v_sum(v1.size()); //vector for results
	for (size_t i = 0; i < v_sum.size(); ++i)
		{
			v_sum[i] = v1[i] + v2[i];
		}
	auto end = std::chrono::steady_clock::now();
	const auto diff = std::chrono::duration<double, std::milli>(end - start);
	std::cout << diff.count()/1000<< " s\t";
}

void sum_vector_threads(const std::vector<int>& v1, const std::vector<int> v2, int num_threads) {
	auto start_time = std::chrono::steady_clock::now();
	std::vector<int> v_sum(v1.size()); //vector for results
	//create vector of threads
	std::vector<std::thread> threads(num_threads);

	auto thread_func = [&v1, &v2, &v_sum, &num_threads](int thread_id) {
		int start = v_sum.size() / num_threads * thread_id;
		int end = v_sum.size() / num_threads * (thread_id +1);
		for (size_t i = start; i < end; ++i) 
		{
			v_sum[i] = v1[i] + v2[i];
		}
	};
	//std::this_thread::sleep_for(10ms);
	for (int thread_id = 0; thread_id < num_threads; ++thread_id) {
		threads[thread_id] = std::thread(thread_func, thread_id);
	}
	for (int thread_id = 0; thread_id < num_threads; ++thread_id) {
		threads[thread_id].join();
	}
	auto end_time = std::chrono::steady_clock::now();
	auto diff = std::chrono::duration<double, std::milli>(end_time - start_time);
	std::cout << diff.count()/1000 << " s\t";
	//print_v(v_sum);
}

int main() {
	setlocale(LC_ALL, "ru");
	//Распараллельте эту программу на 2, 4, 8 и 16 потоков
	int num_threads = 1;
	//доступное количество аппаратных ядер
	std::cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;
	//1 поток
	size_t size = 1000;
	std::vector<int> v1(randomize_v(size));
	std::vector<int> v2(randomize_v(size));
	std::cout << "\t\t1000\t\t" << "10000\t\t" << "100000\t\t" << "1000000\t\t" << std::endl;
	std::cout << "1 поток\t\t";
	sum_vector(v1, v2);
	size = 10000;
	v1 = randomize_v(size);
	v2 = randomize_v(size);
	sum_vector(v1, v2);
	size = 100000;
	v1 = randomize_v(size);
	v2 = randomize_v(size);
	sum_vector(v1, v2);
	size = 1000000;
	v1 = randomize_v(size);
	v2 = randomize_v(size);
	sum_vector(v1, v2);
	
	//2 потока
	std::cout << "\n2 потока\t";
	num_threads = 2;
	size = 1000;
	sum_vector_threads(v1, v2, num_threads);
	size = 10000;
	v1 = randomize_v(size);
	v2 = randomize_v(size);
	sum_vector_threads(v1, v2, num_threads);
	size = 100000;
	v1 = randomize_v(size);
	v2 = randomize_v(size);
	sum_vector_threads(v1, v2, num_threads);
	size = 1000000;
	v1 = randomize_v(size);
	v2 = randomize_v(size);
	sum_vector_threads(v1, v2, num_threads);

	//4 потока
	std::cout << "\n4 потока\t";
	num_threads = 4;
	size = 1000;
	sum_vector_threads(v1, v2, num_threads);
	size = 10000;
	v1 = randomize_v(size);
	v2 = randomize_v(size);
	sum_vector_threads(v1, v2, num_threads);
	size = 100000;
	v1 = randomize_v(size);
	v2 = randomize_v(size);
	sum_vector_threads(v1, v2, num_threads);
	size = 1000000;
	v1 = randomize_v(size);
	v2 = randomize_v(size);
	sum_vector_threads(v1, v2, num_threads);

	//8 потоков
	std::cout << "\n8 потоков\t";
	num_threads = 8;
	size = 1000;
	sum_vector_threads(v1, v2, num_threads);
	size = 10000;
	v1 = randomize_v(size);
	v2 = randomize_v(size);
	sum_vector_threads(v1, v2, num_threads);
	size = 100000;
	v1 = randomize_v(size);
	v2 = randomize_v(size);
	sum_vector_threads(v1, v2, num_threads);
	size = 1000000;
	v1 = randomize_v(size);
	v2 = randomize_v(size);
	sum_vector_threads(v1, v2, num_threads);

	//16 потоков
	std::cout << "\n16 потоков\t";
	num_threads = 16;
	size = 1000;
	sum_vector_threads(v1, v2, num_threads);
	size = 10000;
	v1 = randomize_v(size);
	v2 = randomize_v(size);
	sum_vector_threads(v1, v2, num_threads);
	size = 100000;
	v1 = randomize_v(size);
	v2 = randomize_v(size);
	sum_vector_threads(v1, v2, num_threads);
	size = 1000000;
	v1 = randomize_v(size);
	v2 = randomize_v(size);
	sum_vector_threads(v1, v2, num_threads);
	
	return 0;
}