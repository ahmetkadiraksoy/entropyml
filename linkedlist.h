#include <iostream>
#include <string>

using namespace std;

struct node
{
	int occurance;
	string text;
	node* next;
	node* prev;
};

typedef node* NodePtr;

class LinkedList
{
	public:
		LinkedList ();
		LinkedList (string);
		string get_text(int);
		int get_occurance(int);
		int size();
		bool empty();
		void add (string);
		void increment_occurance (int);
		void remove (int);
		void sort(int);
		void set_text (int, string);
		void set_occurance (int, int);
		void clear();
		NodePtr get_head();
	private:
		NodePtr head;
		NodePtr tail;
		int list_size;
};
