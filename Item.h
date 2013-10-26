#include <cstdlib>
#include <ostream>
#include <cstring>

/* ITEM CLASS

	This class contains the data for an item
	that one might move when moving to a new
	residence. It contains basic information
	such as the name of the item, its volume,
	and its weight in kg. Later implementations
	would contain its full dimensions.

	This class also overloads the = operator,
	in order to efficiently utilize the
	template classes that I wrote in the past.
	The = operator simply invokes Item's method
	"copyItem"

*/

class Item
{
public:
	Item(void); // Default constructor
	Item(char* n, double w, double v); // Overloaded constructor
	~Item(void); // Destroys name

	int createItem(char* n, double w, double v); // For default-constructed Items
	int copyItem(const Item & i); // To push all data at once from another Item
	int retrieve(char* n, double& w, double& v) const;
	int retrieve(Item & i); // To pull all data at once to another Item

	Item& operator=(const Item& right); // Operator overload invokes copyItem
private:
	friend std::ostream& operator<<(std::ostream& out, const Item* const item);
	char* name; // The name of the item
	double weight; // The weight of the item
	double volume; // The item's volume
};

std::ostream& operator<<(std::ostream& out, const Item* const item);