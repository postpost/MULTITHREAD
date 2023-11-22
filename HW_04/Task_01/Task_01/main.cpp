#include <iostream>
#include <vector>

struct C {
	int x, y, z;
	C(int x, int y, int z) :x(x), y(y), z(z) {};
};
struct S {
	std::vector<C> coord;
};

int main() {
	/*a = abs(x1 - x2);
b = abs(y1 - y2);
c = abs(z1 - z2);*/
	int a, x1, x2;
	std::vector<C>my_v;
	my_v.push_back(C(1, 3, 5));
	my_v.push_back(C(10, 30, 50));
	std::vector<C>::iterator it = my_v.begin();
	
	for (; it != my_v.end(); ++it) {
		//std::cout << (*it).x << std::endl;
		//x1 = (*it).x;
		for (auto itr = it+1; itr != my_v.end(); ++itr) {
			//x2 = (*itr).x;
			//a = abs(x1 - x2);
			a = abs((*it).x - (*itr).x);
			std::cout << a << " ";
		}
	}
	return 0;
}