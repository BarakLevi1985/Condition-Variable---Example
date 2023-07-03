#pragma once

#include "Helper.h"

class Consumer {
	// static, internal globals :
	static Lockers _lockers;

	// globals (by reference) :
	stack<string>& _global_stack;

	// parameters :
	string _color;
	int _millisecondsToWait;

	// the vector of names :  
	list<string> _names;
	int _size;

public:
	Consumer(stack<string>& global_stack, string color, 
		int millisecondsToWait, int size);

	void operator() (); 

	list<string> get_names() const;
}; 