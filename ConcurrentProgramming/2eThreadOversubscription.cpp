#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

// 2. Thread Management
// https://www.youtube.com/watch?v=f2nMqNj7vxE&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M&index=2

// Thread Oversubscription
// https://en.cppreference.com/w/cpp/thread/thread/hardware_concurrency

int main() {
	unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported." << std::endl;
	return 0;
}
