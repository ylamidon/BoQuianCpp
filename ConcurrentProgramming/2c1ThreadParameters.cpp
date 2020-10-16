#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

// 2. Thread Management
// https://www.youtube.com/watch?v=f2nMqNj7vxE&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M&index=2

// Passing parameters to a thread 1 : pass by value

class Fctor {
public:
	void operator()(std::string msg) {
		std::cout << "t1 says: " << msg << std::endl;
	}
};

int main() {
	std::string s = "Where there is no trust, there is no love";
	Fctor fct;
	std::thread t1(fct, s);

	try {
		std::cout << "from main: " << s << std::endl;
	} catch (...) {
		t1.join();
		throw;
	}
	t1.join();
	return 0;
}
// Parameters are always passed by value (copied).  
// Why? same reason as bind(): deferred execution means the parameter objects might not be valid at the time of execution.
// To pass by reference:
// 1. use std::ref
// 2. use pointer
