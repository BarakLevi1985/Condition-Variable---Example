#include "Helper.h"

// globals: 
clock_t start;
unsigned seed;

stack<string> shared_names; 

mutex Lockers::_mtx_cout;
mutex Lockers::_mtx_global_stack;
condition_variable Lockers::_cond_global_stack;


// functions : 
void init() {
    static bool isCalled = false;
    if (!isCalled)
    {
        isCalled = true;
        start = clock();
        srand(time(0));
        seed = system_clock::now().time_since_epoch().count();
    }
}

// get a random number [lb - ub] 
int get_random_number(int lb, int ub) {
    return (rand() % (ub - lb + 1)) + lb;
}

void show_names(vector<string> vec, string vec_name) {
    cout << "size of " << vec_name << " : " << vec.size()
        << ", and containing : " << endl << vec << endl << endl;
}
void show_names(list<string> list, string list_name) {
    cout << "size of " << list_name << " : " << list.size()
        << ", and containing : " << endl << list << endl << endl;
}
void show_names(stack<string> stack, string stack_name) {
    cout << endl << "size of " << stack_name << " : " << stack.size()
        << ", and containing : " << endl << "{";
    if (!stack.empty()) 
    {
        cout << stack.top();
        stack.pop();
        while (!stack.empty())
        {
            cout << ", " << stack.top();
            stack.pop();
        }
    }
    cout << "}" << endl << endl;
}
