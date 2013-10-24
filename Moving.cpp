#include "Moving.h"

Moving::Moving(void)
{

}

Moving::~Moving(void)
{

}

int Moving::addToDonations(char* n, double w, double v)
{
	Item toAdd(n, w, v);
	donations.enqueue(toAdd);
}
 
int Moving::addToLoading(char* n, double w, double v)
{
	Item toAdd(n, w, v);
	loading.enqueue(toAdd);
}

int Moving::addToTruck(char* n, double w, double v)
{
	Item toAdd(n, w, v);
	truck.push(toAdd);
}

int Moving::addToUStore(char* n, double w, double v)
{
	Item toAdd(n, w, v);
	ustore.push(toAdd);
}
	
int Moving::displayDonations(void)
{
	//cout << "\n\nDISPLAYING ITEMS STAGED FOR DONATION" << endl;
	//donations.displayAll();
}

int Moving::displayLoading(void)
{
	//cout << "\n\nDISPLAYING ITEMS STAGED FOR LOADING" << endl;
	//loading.displayAll();
}

int Moving::displayTruck(void)
{
	//cout << "\n\nDISPLAYING ITEMS LOADED INTO TRUCK" << endl;
	//truck.displayAll();
}

int Moving::displayUStore(void)
{
	//cout << "\n\nDISPLAYING ITEMS LOADED INTO U-STORE" << endl;
	//ustore.displayAll();
}

// Invokes all of the above
int Moving::displayAll(void)
{
	//cout << "\n\n\nDISPLAYING EVERYTHING\n" << endl;
	//displayDonations();
	//displayLoading();
	//displayTruck();
	//displayUStore();
}

// Removes the next item from the Donations Staging
int Moving::rmvFromDonations(Item& i)
{
	return donations.dequeue(i);
}

// Removes the next item from the Loading Staging
int Moving::rmvFromLoading(Item& i)
{
	return loading.dequeue(i);
}

// Removes the next item from the Truck Storage
int Moving::rmvFromTruck(Item& i)
{
	truck.peek(i);
	return truck.pop();
}

// Removes the next item from the U-Store Storage
int Moving::rmvFromUStore(Item& i)
{
	ustore.peek(i);
	return ustore.pop();
}

// Deletes all the items you spent years collecting
int Moving::burnEverythingAndStartOver(void)
{

}
