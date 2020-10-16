#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

// 2. Thread Management
// https://www.youtube.com/watch?v=f2nMqNj7vxE&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M&index=2

// A thread object cannot be copied
// But it can be moved.  Like fstream, unique_ptr, etc.

class Fctor {
public:
	void operator()(std::string msg) {
		std::cout << "t1 says: " << msg << std::endl;
	}
};

int main() {
	std::cout << "parent thread id: " << std::this_thread::get_id() << std::endl; // print the parent thread id
	std::string s = "Where there is no trust, there is no love";
	Fctor fct;
	std::thread t1(fct, std::move(s));
	std::cout << "child thread id: " << t1.get_id() << std::endl; // print the child thread id
	std::thread t2 = std::move(t1);  // move t1
	t2.join();
	return 0;
}
