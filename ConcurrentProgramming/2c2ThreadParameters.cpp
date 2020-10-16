#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

// 2. Thread Management
// https://www.youtube.com/watch?v=f2nMqNj7vxE&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M&index=2

// Passing parameters to a thread 2 : pass by reference

class Fctor {
public:
	void operator()(std::string& msg) {
		std::cout << "t1 says: " << msg << std::endl;
		msg = "Trust is the mother of deceit.";
	}
};

int main() {
	std::string s = "Where there is no trust, there is no love";
	Fctor fct;
	//std::thread t1(fct, s); // s will remain the same
	std::thread t1(fct, std::ref(s)); // s will be modified
	t1.join();
	std::cout << "from main: " << s << std::endl;
	return 0;
}
// Parameters are always passed by value (copied).  
// Why? same reason as bind(): deferred execution means the parameter objects might not be valid at the time of execution.
// To pass by reference:
// 1. use std::ref
// 2. use pointer
