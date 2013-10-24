#include "Moving.h"

Moving::Moving(void){ }
Moving::~Moving(void){ }

int Moving::addToDonations(char* n, double w, double v){ }
int Moving::addToLoading(char* n, double w, double v){ }
int Moving::addToTruck(char* n, double w, double v){ }
int Moving::addToUStore(char* n, double w, double v){ }
	
int Moving::displayDonations(void){ }
int Moving::displayLoading(void){ }
int Moving::displayTruck(void){ }
int Moving::displayUStore(void){ }
int Moving::displayAll(void){ } // Invokes all of the above

int Moving::rmvFromDonations(Item& i){ } // Removes the next item from the Donations Staging
int Moving::rmvFromLoading(Item& i){ } // Removes the next item from the Loading Staging
int Moving::rmvFromTruck(Item& i){ } // Removes the next item from the Truck Storage
int Moving::rmvFromUStore(Item& i){ } // Removes the next item from the U-Store Storage

int Moving::burnEverythingAndStartOver(void){ } // Deletes all the items you spent years collecting
