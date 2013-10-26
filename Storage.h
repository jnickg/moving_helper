#include <cstdlib>
#include <iostream>

/* Storage (LINEAR LINKED LIST)
Storage.h
jnickg (jnickg83@gmail.com)
Created 17 Oct 2013

See description below.

THIS IS A TEMPLATE CLASS WHICH REQUIRES FUNCTION
IMPLEMENTATIONS INSIDE THE .h FILE

*/

#ifndef LLPSTRUCT
#define LLPSTRUCT
template <class T> struct nodep
{
	T* data;
	nodep<T>* next;
};
#endif // LLPSTRUCT

const int MAX = 5; // Change this for larger arrays in LLPSTRUCT

/* TEMPLATE CLASS DESCRIPTION
	Your standard Storage class, which is capable
	of basic operations such as push, pop.

	Use of this template requires that T has an
	efficiently-implemented operator= overload,
	as this template class simply uses operator=

	Uses arrays of Ts for each nodep, rather than
	individual Ts. Each array is of size MAX
	(default: 5)

	Version			1.0
	Written by		Nick Giampietro (jnickg)
	On				17 October 2013
END TEMPLATE CLASS DESCRIPTION */
template <class T> class Storage
{
public:
	Storage(void)
	{
		top = NULL;
		size = 0;
	}

	~Storage(void)
	{
		nodep<T>* tmp;
		while(top)
		{
			tmp = top;
			delete [] top->data;
			top = top->next;
			delete tmp;
			tmp = NULL;
		}
	}

	int push(const T & data)
	{
		// Case 1: No items yet
		if(NULL == top)
		{
			top = new nodep<T>;
			top->data = new T[MAX];
			top->data[size%MAX] = data;
			top->next = NULL;
			++size;
		}
		// Case 2: An array is full
		else if((size%MAX)==0) // == because 0-4 is 5 entries
		{
			// Add new nodep of array of journal entries
			nodep<T>* tmp = new nodep<T>;
			tmp->data = new T[MAX];
			tmp->data[size%MAX] = data;

			// Reassign top of stack
			tmp->next = top;
			top = tmp;
			++size;
		}
		// Case 3: Room in current array
		else
		{
			top->data[size%MAX] = data;
			++size;
		}

		return size;
	}

	int pop(void)
	{
		// Case 1: Empty stack yo.
		if(NULL == top) return 0;

		// Case 2: Got to da bottom of da stack yo.
		else if((size%MAX)==0)
		{
			nodep<T>* tmp = top;
			delete [] tmp->data;
			top = top->next;
			delete tmp;
			if((--size)<0) size=0;
			return 1;
		}

		// Case 3: Middle of the current stack!
		else
		{
			--size;
			return 1;
		}
	}

	int peek(T & data)
	{
		if(top)
		{
			data = top->data[size%MAX];
			return size;
		}
		else return size;
	}

	// Return int is current size.
	int getsize(void)
	{
		return size;
	}

	std::ostream& displayAll(std::ostream& out) const
	{
		nodep<T>* tmp = top;
		
		while(tmp)
		{
			out << tmp->data << std::endl;
			tmp = tmp->next;
		}
		
		return out;
	}
private:
	int size; // Current size
	nodep<T>* top; // Pointer to the top of the stack
};

