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

	/**
	// check if empty 
	for (int i = 0; i < _size; ++i)
	{
		{
			lock_guard lck(_lockers._mtx_global_stack);
			if (!_global_stack.empty())
			{
				name = _global_stack.top();
				_global_stack.pop();
			}
		}

		_names.push_back(name);

		current = clock(); // get the current time
		current_time = (double)(current - start) / CLOCKS_PER_SEC;

		{
			lock_guard lck_cout(_lockers._mtx_cout);
			cout << Colors[_color] << "At " << current_time << " seconds "
				<< name << " was poped out by the Consumer thread. "
				<< Colors["white"] << endl;
		}

		// sorting.. 
		_names.sort();

		// sleeping..
		sleep_for(milliseconds(_millisecondsToWait));
	}
	/**/

	/**/
	// check if empty and if Entered 
	bool isEntered;

	for (int i = 0; i < _size; ++i)
	{
		{
			unique_lock lck(_lockers._mtx_global_stack);
			_lockers._cond_global_stack.wait(lck, [this]() { return !_global_stack.empty(); });
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
	/**/
}

list<string> Consumer::get_names() const {
	return _names; 
}
