#include <iostream>
#include "Staging.h"
#include "Storage.h"
#include "Item.h"

class Moving
{
public:
	Moving(void);
	~Moving(void);

	int addToDonations(char* n, double w, double v);
	int addToLoading(char* n, double w, double v);
	int addToTruck(char* n, double w, double v);
	int addToUStore(char* n, double w, double v);
	
	std::ostream& displayDonations(std::ostream& out) const;
	std::ostream& displayLoading(std::ostream& out) const;
	std::ostream& displayTruck(std::ostream& out) const;
	std::ostream& displayUStore(std::ostream& out) const;
	std::ostream& displayAll(std::ostream& out) const; // Invokes all of the above

	int rmvFromDonations(Item& i); // Removes the next item from the Donations Staging
	int rmvFromLoading(Item& i); // Removes the next item from the Loading Staging
	int rmvFromTruck(Item& i); // Removes the next item from the Truck Storage
	int rmvFromUStore(Item& i); // Removes the next item from the U-Store Storage

	int burnEverythingAndStartOver(void); // Deletes all the items you spent years collecting

private:
	Staging<Item> donations;
	Staging<Item> loading;
	Storage<Item> truck;
	Storage<Item> ustore;
};

std::ostream& operator<<(std::ostream& out, const Moving* const mov);