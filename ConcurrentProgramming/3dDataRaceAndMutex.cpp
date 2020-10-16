#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

// 3. Data Race and Mutex
// https://www.youtube.com/watch?v=3ZxZPeXPaM4&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M&index=3

// Interface is not thread safe 

class stack {
	int* _data;
	std::mutex _mu;
public:
	int& pop(); // pops off the item on top of the stack
	int& top(); // returns the item on top
	//...
};

// Not thread safe:
void function1(stack& st) {
	int v = st.top();
	st.pop();
	process(v);
}

// Thread safe:
void function1(stack& st) {
	int v = st.pop();
	process(v);
}

// Conclusion
//
// Avoiding Data Race:
// 1. Use mutex to synchronize data access;
// 2. Never leak a handle of data to outside
// 3. Design interface appropriately.
