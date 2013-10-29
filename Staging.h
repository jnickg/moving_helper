#include <cstdlib>

/* Staging (CIRCULAR LINKED LIST)
Staging.h
jnickg (jnickg83@gmail.com)
Created 17 Oct 2013

See description below

THIS IS A TEMPLATE CLASS WHICH REQUIRES FUNCTION
IMPLEMENTATIONS INSIDE THE .h FILE

*/

#ifndef LLSTRUCT
#define LLSTRUCT
template <class T> struct node
{
	T data;
	node<T>* next;
};
#endif // LLSTRUCT

/*	Staging (Circular Linked List)
	
	A linear linked list is a series of nodes
	which contain pointers to other nodes. Each
	node contains an object of type T, which allows
	this class to be useful in any situation.

	The size of a List is flexible, and sentinel
	nodes track the head and last elements in the
	list. Add and remove operations can be done
	from either side of the list. Iteration is
	possible through an additional sentinel node,
	which can be manipulated through the it_
	functions.

	Use of this template requires that T has an
	efficiently-implemented operator= overload,
	as this template class simply uses operator=

	Use of this template requires that T has a
	function with the following signature:
	std::ostream& T::print(std::ostream& out) const
	or else it will not compile correctly.

*/
template <class T> class Staging
{
public:
	Staging(void)
	{
		home = NULL;
		count = 0;
	}

	~Staging(void)
	{

	}

	// Adds new data to the CLL queue
	//
	// Return int is the new count.
	int enqueue(const T & data)
	{
		// Case 1: empty
		if(NULL == home)
		{
			home = new node<T>;
			home->data = data;

			home->next = home;

			return ++count;
		}
		// Case 2: one-item queue
		else if(home->next == home)
		{
			node<T>* tmp = new node<T>();
			tmp->data = data;

			home->next = tmp;
			tmp->next = home;
			home = tmp;
			
			return ++count;
		}
		// Case 3: more
		else
		{
			// tmp holds on to first-in
			node<T>* tmp = home->next;
			
			// Append new node to last-in
			home->next = new node<T>();
			home->next->data = data;
			// Reassign home to new last-in
			home = home->next;
			// Reassign home->next to first-in
			home->next = tmp;

			return ++count;
		}
	}

	// Returns 1 if something was dequeued
	// Returns 0 otherwise
	int dequeue(T & data)
	{
		if(NULL == home)
		{
			return 0;
		}
		else if(home->next == home)
		{
			data = home->data;
			
			delete home;
			home = NULL;

			return 1;
		}
		else
		{
			// Retrieve first-in
			data = home->next->data;

			node<T>* tmp = home->next->next;
			delete home->next;
			home->next = tmp;

			return 1;
		}
	}

	int peek(T & data)
	{
		if(NULL == home)
		{
			return 0;
		}
		else
		{
			data = home->data;
			return 1;
		}
	}

	int getCount(void)
	{
		return count;
	}

	std::ostream& displayAll(std::ostream& out) const
	{
		if(home)
		{
			node<T>* tmp = home->next;
			do
			{
				tmp->data.print(out);
				tmp = tmp->next;
			} while(tmp!=home->next);
		}
		return out;
	}

private:
	node<T>* home; // The 'home' location for the CLL
	int count; // The number of nodes
};

