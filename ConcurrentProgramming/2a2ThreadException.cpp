#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

// 2. Thread Management
// https://www.youtube.com/watch?v=f2nMqNj7vxE&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M&index=2

// Dealing with exceptions 2

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

// Solution 2: RAII
class ThreadJoiner {
	std::thread& m_th;
public:
	explicit ThreadJoiner(std::thread& t) : m_th(t) {}
	~ThreadJoiner() {
		if (m_th.joinable()) {
			m_th.join();
		}
	}
};

int main() {
	std::thread t1(function1); // t1 starts running
	ThreadJoiner tj(t1);
	for (int i=0; i<100; i++)
		std::cout << "from main: " << i << std::endl;
	return 0;
}

// We can also create a ThreadDetacher class
// Prerequisit: join() or detach() can happen at the end of the function
