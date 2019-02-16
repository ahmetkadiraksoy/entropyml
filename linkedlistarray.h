#include "linkedlist.h"
#include <iostream>

using namespace std;

struct node2
{
	LinkedList item;
	node2* next;
};

typedef node2* NodePtr2;

class LinkedListArray
{
	public:
		LinkedListArray ();
		LinkedList get_item(int);
		int size();
		bool empty();
		void add(LinkedList);
		void remove (int);
		void set_item (int, LinkedList);
		void clear();
		NodePtr2 get_array_head();
	private:
		NodePtr2 head2;
};
