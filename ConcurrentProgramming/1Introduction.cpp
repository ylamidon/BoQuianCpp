#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

// 1. Introduction
// https://www.youtube.com/watch?v=LL8wkskDlbs&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M&index=1

// First example:

void function1() {
	std::cout << "Beauty is only skin-deep" << std::endl;
}

int main() {
	std::thread t1(function1);
	t1.join();      // main thread wait for t1 to finish
	//t1.detach();  // main thread let t1 to run on its own: t1 is a daemon process.
                    // C++ runtime library is responsible returning t1's resources
                    // and main thread may finish before t2 prints "Hello"
	return 0;
}

// If neither detach nor join is called, terminate() will be called for the t1.

// A thread can only be joined once or detached once. After it is joined on detached it becomes unjoinable ( t.joinable() returns false )



