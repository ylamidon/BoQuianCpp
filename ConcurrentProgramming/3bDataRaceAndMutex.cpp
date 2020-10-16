#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

// 3. Data Race and Mutex
// https://www.youtube.com/watch?v=3ZxZPeXPaM4&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M&index=3

// Using mutex to synchronize threads

std::mutex mu;

void shared_print(std::string msg, int id) {
	std::lock_guard<std::mutex> locker(mu); // RAII
	//mu.lock();
	std::cout << msg << id << std::endl; // Exception may happen here -> mu in never unlocked if we don't use lock_guard
	//mu.unlock();
}

void function1() {
	for (int i=0; i>-100; i--)
		shared_print(std::string("from t1: "), i);
}

int main() {
	std::thread t1(function1);
	for (int i=0; i<100; i++)
		shared_print(std::string("from main: "), i);
	t1.join();
	return 0;
}
