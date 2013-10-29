#include <iostream>
#include <cstring>
#include "Moving.h"

using namespace std;

int getInput(char*& n, double& w, double& v);

int main(void)
{
	char menu; // for user menu input
	char* n = NULL; // for user Item-class input
	double w, v; // for user Item-clas sinput
	Moving kmh; // Karla's Mom's House!
	Item tmp; // Temporary storage used to printing dequeued/popped items

	cout << "\n\nBACKSTORY:\n\n"
		 << "\"Recently  I  have  spent  the  last  few  weeks\n"
		 << "preparing  my  parents  house  for  sale  and\n"
		 << "moving  the  remaining  belongings  to various\n"
		 << "locations. Some of the belongings my mom wanted\n"
		 << "to keep (she got first pick!).  Then  others  went\n"
		 << "to  my  house  or  my  sisters  house  (you\n"
		 << "should  see  my front entry – it is stacked with\n"
		 << "boxes!). Others went into storage, Salvation Army,\n"
		 << "or the dump. So you can imagine, moving a 3000\n"
		 << "square foot house I had queues built for each of\n"
		 << "the different destinations. But, then with the\n"
		 << "storage unit, I had to make sure that I ordered it\n"
		 << "such that the last item in was to be the first\n"
		 << "item back out (LIFO)  –  placing  items I need to\n"
		 << "access soon up front and pushing data early on\n"
		 << "that I don’t expect to need.\"" << endl;

	cout << "\nLet's help Karla move her mum!\n" << endl;

	do {
		// Menu
		cout << "Please enter one of the below commands:\n"
			 << "add to\n"
			 << "\t<D>onations queue\n"
			 << "\t<L>oading queue\n"
			 << "\t<M>oving truck stack\n"
			 << "\t<U>-store pod stack\n"
			 << "<V>iew everything so far\n"
			 << "<R>emove one item from each\n"
			 << "<B>urn everything and start over (bad idea)\n"
			 << "e<X>it program\n" << endl;
			 
		cout << ">";
			cin >> menu;
			cin.ignore(100, '\n');
		
		if (menu == 'D') {
			getInput(n, w, v);
			kmh.addToDonations(n, w, v);
		}

		else if (menu == 'L') {
			getInput(n, w, v);
			kmh.addToLoading(n, w, v);
		}

		else if (menu == 'M') {
			getInput(n, w, v);
			kmh.addToTruck(n, w, v);
		}

		else if (menu == 'U') {
			getInput(n, w, v);
			kmh.addToUStore(n, w, v);
		}

		else if (menu == 'V') {
			kmh.displayAll(cout);
		}

		else if (menu == 'R') {
			if(kmh.rmvFromDonations(tmp))
			cout << "Removed from Donations:\n"
				 << &tmp << endl;
			if(kmh.rmvFromLoading(tmp))
			cout << "Removed from Loading:\n"
				 << &tmp << endl;
			if(kmh.rmvFromTruck(tmp))
			cout << "Removed from Truck:\n"
				 << &tmp << endl;
			if(kmh.rmvFromUStore(tmp))
			cout << "Removed from U-Store:\n"
				 << &tmp << endl;
		}
		
		else if (menu == 'B') {
			cout << "...okay...\n" << endl;
			kmh.burnEverythingAndStartOver();
		}

		else if (menu == 'X') {
			cout << "kthxby\n" << endl;
		}
		
		else {
			cout << "BAD INPUT. Make sure you used upper-case\n" << endl;
		}
		
	
	} while(menu != 'X');
	
	cout << "\n\n\n\nTERMINATING PROGRAM\n";

	return 0;
}

int getInput(char*& n, double& w, double& v)
{
	char buffer[512];

	cout << "\nNew item info:"
		 << "\n(string) name>\t";
	cin >> buffer;
	cin.ignore(100, '\n');

	
	if(n) delete n; // Avoid leaks
	// Cast from buffer to n
	n = new char[strlen(buffer)+1];
	strcpy(n, buffer);

	cout << "(double) weight>";
	cin >> w;
	cin.ignore(100, '\n');

	cout << "(double) volume>";
	cin >> v;
	cin.ignore(100, '\n');

	return 1;
}
