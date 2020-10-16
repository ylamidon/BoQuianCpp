#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

// 3. Data Race and Mutex
// https://www.youtube.com/watch?v=3ZxZPeXPaM4&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M&index=3

// Race condition

void function1() {
	for (int i=0; i>-100; i--)
		std::cout << "from t1: " << i << std::endl;
}

int main() {
	std::thread t1(function1);
	for (int i=0; i<100; i++)
		std::cout << "from main: " << i << std::endl;
	t1.join();
	return 0;
}
