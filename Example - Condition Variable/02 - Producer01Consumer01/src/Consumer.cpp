#include "Consumer.h"

// init static : 
Lockers Consumer::_lockers;

// functions :
Consumer::Consumer(stack<string>& global_stack,	string color,
	int millisecondsToWait, int size) :
	_global_stack(global_stack), _color(color),
	_millisecondsToWait(millisecondsToWait), _size(size) {}

void Consumer::operator() () {
	clock_t current;
	double current_time;
	
	string name; 
	
	for (int i = 0; i < _size; ++i)
	{
		{
			lock_guard lck(_lockers._mtx_global_stack);
			name = _global_stack.top();
			_global_stack.pop();
		}

		_names.push_back(name);

		current = clock(); // get the current time
		current_time = (double)(current - start) / CLOCKS_PER_SEC;

		{
			lock_guard lck_cout(_lockers._mtx_cout);
			cout << "At " << current_time << " seconds "
				<< Colors[_color] << name << Colors["white"]
				<< " was poped out by the Consumer. " << endl;
		}

		// sorting.. 
		_names.sort(); 

		// sleeping..
		sleep_for(milliseconds(_millisecondsToWait));
	}
}

list<string> Consumer::get_names() const {
	return _names; 
}
