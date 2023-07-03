#include "Helper.h"
#include "Producer.h"
#include "Consumer.h"


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

	show_names(names1, "names1");

	system("pause>nul");

	Producer producer1(shared_names, "green", 450, names1);
	Consumer consumer1(shared_names, "purple", 150, names1.size());
	
	/**
	producer1();
	consumer1();
	/**/

	/**/
	thread tP(ref(producer1));
	sleep_for(milliseconds(350));
	thread tC(ref(consumer1));
	tP.join();
	tC.join();
	/**/

	system("pause>nul"); 

	show_names(shared_names, "shared_names");

	system("pause>nul");
	show_names(consumer1.get_names(), "consumer1::names");

	system("pause");

	return 0;
}