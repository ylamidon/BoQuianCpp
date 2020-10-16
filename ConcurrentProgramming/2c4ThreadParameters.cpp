#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

// 2. Thread Management
// https://www.youtube.com/watch?v=f2nMqNj7vxE&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M&index=2

// Passing parameters to a thread 4 : thread with moving parameters

class Fctor {
public:
	void operator()(std::string msg) {
		std::cout << "t1 says: " << msg << std::endl;
	}
};

int main() {
	std::string s = "Where there is no trust, there is no love";
	Fctor fct;
	std::thread t1(fct, std::move(s)); // move s
	// assume s no longer used in the main thread
	t1.join();
	return 0;
}
