#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

// 2. Thread Management
// https://www.youtube.com/watch?v=f2nMqNj7vxE&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M&index=2

// Dealing with exceptions 1

void function1() {
	std::cout << "Beauty is only skin-deep" << std::endl;
}

// Problem : if exception happens in the main()'s for loop, t1.join() will not be called.
int main() {
	std::thread t1(function1); // t1 starts running
	for (int i=0; i<100; i++)
		std::cout << "from main: " << i << std::endl;  // Exception may happen here
	t1.join();
	return 0;
}

// Solution 1:
int main() {
	std::thread t1(function1); // t1 starts running
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
