#include "Producer.h" 

// init static : 
mutex Producer::_mtx_cout;
mutex Producer::_mtx_global_stack;

// functions :
Producer::Producer(stack<string>& global_stack, string color, 
	int millisecondsToWait, vector<string> names) : 
	_global_stack(global_stack), _color(color), 
	_millisecondsToWait(millisecondsToWait), _names(names), _index(0) {}

void Producer::operator() () {
	clock_t current;
	double current_time; 

	for (int i = 0; i < _names.size(); )
	{
		vector<string> random_names = get_random_names(); 

		// insert one by one..  
		/**
		for (auto it = random_names.begin(); it != random_names.end(); ++it)
		{
			if ((*it != "") && (it != random_names.end()))
			{
				{
					lock_guard lck_names(_mtx_global_stack);
					_global_stack.push(*it);
				}
				++i; // increase for each name that inserted to stack  
				current = clock(); // get the current time
				current_time = (double)(current - start) / CLOCKS_PER_SEC;
				{
					lock_guard lck_cout(_mtx_cout);
					cout << Colors[_color] << "At " << current_time << " seconds "
						<< *it << " was inserted by the Prudecer thread. "
						<< Colors["white"] << endl;
				}
			}
		}
		/**/

		// insert 1 or 2 or 3 in one line
		/**/
		{
			lock_guard lck_names(_mtx_global_stack);
			_global_stack.push_range(random_names);
		}
		i += random_names.size(); // increase for each name that inserted to stack  
		current = clock(); // get the current time
		current_time = (double)(current - start) / CLOCKS_PER_SEC;
		{
			lock_guard lck_cout(_mtx_cout);
			cout << "At " << current_time << " seconds " << Colors[_color]
				<< random_names << Colors["white"] 
				<< " was inserted by the Prudecer. " << endl;
		}
		/**/

		/**
		// just for debug .. 
		cout << "_names : " << endl << _names << endl;
		//system("pause>nul");
		/**/

		// sleeping..
		sleep_for(milliseconds(_millisecondsToWait));
	}
}


string Producer::get_random_name() {
	/**
	// just for debug..
	cout << "_index = " << _index << endl;
	/**/

	shuffle((_names.begin() + _index), _names.end(),
		default_random_engine(seed));

	if (_index < _names.size())
	{
		string res = _names[_index];
		++_index;
		return res;
	}
	else
		return "";
}

vector<string> Producer::get_random_names() {
	int size = get_random_number(1, 3);

	vector<string> res;

	for (int i = 0; i < size; ++i)
		res.push_back(get_random_name());

	// just for remove empty strings ("") 
	auto it = std::remove(res.begin(), res.end(), "");
	res.erase(it, res.end());

	return res;
}
