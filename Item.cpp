#include "Item.h"

// Default constructor
Item::Item(void)
{
	name = NULL;
	weight = 0;
	volume = 0;
}

// Constructor which takes default values and assigns
// them to this.
Item::Item(char* n, double w, double v)
{
	name = n;
	weight = w;
	volume = v;
}

// Deletes name
Item::~Item(void)
{
	if(name) delete name;
	name = NULL;
}

// Used if default constructor was invoked.
int Item::createItem(char* n, double w, double v)
{
	name = n;
	weight = w;
	volume = v;
}

// Returns 1 if it was able to copy all data from i
// Returns 0 if i's name was NULL
int Item::copyItem(const Item & i)
{
	// Retrieve data from i
	int worked;
	char* n;
	double w, v;
	worked = i.retrieve(n, w, v);

	// Assign i's data to this
	strcpy(name, n);
	weight = w;
	volume = v;

	return worked;
}

// Returns 1 if it was able to copy all data from the Item
// Returns 0 if there was no name
int Item::retrieve(char* n, double& w, double& v) const
{
	if(name)
	{
		strcpy(n, name);
		w = weight;
		v = volume;
		return 1;
	}
	else
	{
		n = NULL;
		w = weight;
		v = volume;
	}
}

// Uses operator= and therefore the copyItem method
// to copy data from this to i
int Item::retrieve(Item & i)
{
	i = *this;
}

// Displays all data from this to cout
//
// Used for debugging and troubleshooting
int Item::display(void)
{

}

Item& Item::operator=(const Item& right)
{
	this->copyItem(right);
	return *this;
}
