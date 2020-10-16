#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

// 2. Thread Management
// https://www.youtube.com/watch?v=f2nMqNj7vxE&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M&index=2

// Passing parameters to a thread 3 : pass a class method

// To pass a class method as thread's initial function, use pointers
class A {
public:
	void call_from_thread(std::string* msg) {
		*msg = "Beauty is only skin-deep";
		std::cout << "t1 says: " << *msg << std::endl;
	}
};

int main() {
	std::string s = "A friend in need is a friend indeed.";
	A a;
	std::thread t1(&A::call_from_thread, &a, &s);
	//t1.detach();
	t1.join();
	std::cout << "main says: " << s << std::endl;
	return 0;
}