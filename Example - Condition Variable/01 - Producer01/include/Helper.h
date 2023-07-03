#pragma once

#include <thread>
#include <string>
#include <vector>
#include <list>
#include <mutex>
#include <algorithm>
#include <random>
#include <chrono>
#include <stack>

#include "Colors.h"

// usings : 
using std::stack; 
using std::string;
using std::vector;
using std::list;
using std::thread;
using std::mutex;
using std::lock_guard;

using std::unique_lock;
using std::condition_variable; 

using std::cout;
using std::endl;

using std::ref; 

using std::chrono::milliseconds;
using std::this_thread::sleep_for; 

using std::sort;
using std::shuffle;

using std::chrono::system_clock;
using std::default_random_engine;

// globals: 
extern clock_t start;
extern unsigned seed;

extern stack<string> shared_names;

// functions : 
void init();

// get a random number [lb - ub] 
int get_random_number(int lb, int ub); 

void show_names(vector<string> vec, string vec_name);
void show_names(stack<string> stack, string stack_name);

// temlates : 
template<typename Os, typename Container>
Os& operator<<(Os& os, Container const& cont)
{
	if (cont.empty())
		os << "{}";
	else
	{
		os << "{";
		auto it = cont.begin();
		os << *it++;
		for (; it != cont.end(); ++it)
			os << ", " << *it;
		os << "}";
	}
	return os;
}
