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

std::ostream& Moving::displayDonations(std::ostream& out) const
{
	out << "\n\nDISPLAYING ITEMS STAGED FOR DONATION" << std::endl;
	donations.displayAll(out);
	return out;
}

std::ostream& Moving::displayLoading(std::ostream& out) const
{
	out << "\n\nDISPLAYING ITEMS STAGED FOR LOADING" << std::endl;
	loading.displayAll(out);
	return out;
}

std::ostream& Moving::displayTruck(std::ostream& out) const
{
	out << "\n\nDISPLAYING ITEMS LOADED INTO TRUCK" << std::endl;
	truck.displayAll(out);
	return out;
}

std::ostream& Moving::displayUStore(std::ostream& out) const
{
	out << "\n\nDISPLAYING ITEMS LOADED INTO U-STORE" << std::endl;
	ustore.displayAll(out);
	return out;
}

// Invokes all of the above
std::ostream& Moving::displayAll(std::ostream& out) const
{
	out << "\n\n\nDISPLAYING EVERYTHING\n" << std::endl;
	displayDonations(out);
	displayLoading(out);
	displayTruck(out);
	displayUStore(out);
	return out;
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

std::ostream& operator<<(std::ostream& out, const Moving* const mov)
{
	mov->displayAll(out);
	return out;
}
