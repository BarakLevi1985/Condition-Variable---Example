#include "Helper.h"
#include "Producer.h"


int main()
{
	init(); 

	vector<string> names1 = {
	"John",
	"Mary",
	"Robert",
	"Jennifer",
	"Michael",
	"David",
	"James",
	"Kimberly",
	"William",
	"Megan",
	"Joseph",
	"Amanda",
	"Christopher",
	"Samantha",
	"Daniel",
	"Matthew",
	"Lauren",
	"Andrew",
	"Ashley",
	"Joshua",
	"Jason",
	"Anthony",
	"Taylor",
	"Brian",
	"Rachel",
	"Kevin",
	"Michelle",
	"Thomas",
	"Olivia",
	"Steven",
	"Stephanie",
	"Richard",
	"Elizabeth",
	"Timothy",
	"Hannah",
	"Nicole",
	"Amber"
	}; 
	vector<string> names2 = { "Yona", "Emily", "Daniella", "Jessica",
	"Arielle", "Tikva", "Naomi", "Liv", "Chen", "Mila", "Sarah", "Rivka",
	"Anna", "Shuli", "Alma", "Katya", "Maya", "Elinor", "Yael", "Roni" }; 

	show_names(names1, "names1");
	show_names(names2, "names2");

	system("pause>nul");

	Producer producer1(shared_names, "green", 300, names1);
	Producer producer2(shared_names, "azure", 500, names2);
	
	/**/
	producer1();
	producer2();
	/**/

	/**
	thread t1(ref(producer1));
	thread t2(ref(producer2));
	t1.join();
	t2.join();
	/**/

	system("pause>nul"); 

	show_names(shared_names, "shared_names");

	system("pause");

	return 0;
}








/**
vector<string> names_list1 = { "Yossi", "Tikva", "Dana", "Ohad" };
vector<string> names_list2 = { "Avraham", "Gadi", "Noam", "Eran" };
vector<string> names_list3 = { "Loren", "Elad", "Motti", "Rivka" };
/**/


/**
// operator ()
#include <string>
#include <mutex>
using std::string;
using std::mutex;
using std::lock_guard;

class Test {
	static mutex _mtx;
	string _color;
	string _toPrint;
	int _times;
	int _millisecondsToWait;
public:
	Test(string color, string toPrint, int times, int millisecondsToWait) :
		_color(color), _toPrint(toPrint), _times(times), _millisecondsToWait(millisecondsToWait) {}
	string res;
	void operator() ()
	{
		for (int i = 0; i < _times; ++i)
		{
			{
				lock_guard lck(_mtx);
				cout << Colors[_color] << _toPrint;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(_millisecondsToWait));
		}
		{
			lock_guard lck(_mtx);
			cout << Colors[_color] << "funColor (" << _toPrint << ") finish ! " << endl << endl;
		}
		res = _toPrint;
	}
	void fun() { cout << "hi" << endl; }
};
mutex Test::_mtx;
/**/

/**
Test* a = new Test("green", "Green ", 40, 130); ;
Test b("white", "White ", 40, 130);
a->res = "bla bla";
b.res = "bla bla bla";
cout << endl << "a.res = " << a->res << endl;
cout << "b.res = " << b.res << endl << endl;

thread t1(std::ref(*a));
thread t2(std::ref(b));



t1.join();
t2.join();
cout << endl << "a.res = " << a->res << endl;
cout << "b.res = " << b.res << endl;
delete a;
a = nullptr;
/**/


/**
class Lock {
public:
	mutex _mtx;
};

void fun(mutex& m, const string c) {
	for (int i = 0; i < 40; ++i)
	{
		{
			lock_guard lck(m);
			cout << Colors[c.c_str()] << c << " ";
		}
		sleep_for(milliseconds(130));
	}
}
/**/
