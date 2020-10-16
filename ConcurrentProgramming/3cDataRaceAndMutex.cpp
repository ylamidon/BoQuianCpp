#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

// 3. Data Race and Mutex
// https://www.youtube.com/watch?v=3ZxZPeXPaM4&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M&index=3

// 1. Avoid global variables (like cout)
// 2. Mutex should bundle together with the resource it is protecting.
 
class LogFile {
	std::mutex m_mutex;
	std::ofstream m_f;
public:
	LogFile() {
		m_f.open("log.txt");
	} // Need destructor to close file
	void shared_print(std::string id, int value) {
		std::lock_guard<std::mutex> locker(m_mutex);
		m_f << "From " << id << ": " << value << std::endl;
	}
	// Never return f to the outside world, like this:
	std::ofstream* getStream() { return &m_f; }
	// Never leak f to outside world, like this:
	void processf(void fun(std::ofstream&)) {
		fun(m_f);
	}
};
// Important: Do not let your user work on protected data directly

class Fctor {
	LogFile& m_log;
public:
	Fctor(LogFile& log) : m_log(log) {}
	void operator()() {
		for (int i=0; i>-100; i--) 
			m_log.shared_print("t1", i);
	}
};

int main() {
	LogFile log;
	Fctor fctor(log);
	std::thread t1(fctor);
	for (int i=0; i<100; i++)
		log.shared_print("main", i);
	t1.join();
	return 0;
}
