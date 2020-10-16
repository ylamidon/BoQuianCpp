#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

// 2. Thread Management
// https://www.youtube.com/watch?v=f2nMqNj7vxE&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M&index=2

// Second Example: Racing condition

class Fctor {
public:
	void operator()() {
		for (int i=0; i>-100; i--)
			std::cout << "from t1: " << i << std::endl;
	}
};

int main() {
	Fctor fct;
	std::thread t1(fct);

	try {
		for (int i=0; i<100; i++)
			std::cout << "from main: " << i << std::endl;  // Exception may happen here
	} catch (...) {
		t1.join();
		throw;
	}
	t1.join();
	return 0;
}
