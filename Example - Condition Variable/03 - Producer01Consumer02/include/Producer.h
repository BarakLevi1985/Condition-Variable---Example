#pragma once

#include "Helper.h"

class Producer {
	// static, internal globals :
	static Lockers _lockers; 

	// globals (by reference) :
	stack<string>& _global_stack;

	// parameters :
	string _color; 
	int _millisecondsToWait;

	// the vector of names :  
	vector<string> _names; 
	int _index; 

	// functions:
	string get_random_name(); 
	vector<string> get_random_names();

public:
	Producer(stack<string>& global_stack, string color, 
		int millisecondsToWait, vector<string> names);

	void operator() ();
};