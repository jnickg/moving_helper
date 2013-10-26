#include <iostream>
#include <cstring>
#include "Moving.h"

using namespace std;

int main(void)
{
	int i = 0; // stores the current length of the app array
	char menu; // for user input
	Moving kmh; // Karla's Mom's House

	cout << "\n\nBACKSTORY:\n\n"
		 << "Recently  I  have  spent  the  last  few  weeks\n"
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
		 << "that I don’t expect to need." << endl;

	cout << "\nLet's help Karla move her mum!\n" << endl;

	do {
		// Menu
		cout << "Please enter one of the below commands:\n"
			 << "add\n\t<N>ew item\n"
			 << "view\n\t<D>onations queue\n"
			 << "\t<L>oading queue\n"
			 << "\t<M>oving truck stack\n"
			 << "\t<U>-store pod stack\n"
			 << "<B>urn everything and start over (bad idea)\n"
			 << "e<X>it program\n" << endl;
			 
			cin >> menu;
			cin.ignore(100, '\n');
		
		if (menu == 'N') {
			editApp(appList[i]);
			++i;
		}
		
		else if (menu == 'V') {
			displayAppAll(appList, i);
		}
		
		else if (menu == 'S') {
			saveAppList(appList, i);
		}
		
		else if (menu == 'L') {
			i = loadAppList(appList);
		}
		
		else if (menu == 'X') {
			cout << "kthxby\n" << endl;
		}
		
		else {
			cout << "BAD INPUT\n" << endl;
		}
		
	
	} while(menu != 'X');
	
	cout << "\n\n\n\nTERMINATING PROGRAM\n";

	return 0;
}
