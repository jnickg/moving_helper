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
	
	int displayDonations(void);
	int displayLoading(void);
	int displayTruck(void);
	int displayUStore(void);
	int displayAll(void); // Invokes all of the above

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
