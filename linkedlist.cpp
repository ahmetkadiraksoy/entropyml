#include <iostream>
#include <string>
#include "linkedlist.h"

LinkedList::LinkedList ()
{
	head = NULL;
	tail = NULL;
	list_size = 0;
}

LinkedList::LinkedList (string text_temp)
{
	head = NULL;
	tail = NULL;
	list_size = 0;
	add(text_temp);
}

int LinkedList::size()
{
	return list_size;
}

void LinkedList::clear ()
{
	NodePtr temp = head;
	NodePtr temp2 = head;
	while(temp != NULL)
	{
		temp2 = temp->next;
		delete temp;
		temp = temp2;
	}
	head = NULL;
	tail = NULL;
	list_size = 0;
}

NodePtr LinkedList::get_head()
{
	return head;
}

void LinkedList::set_text (int pos, string text_temp)
{
	NodePtr temp = head;
	for (int i = 0; i < pos; i++)
	{
		temp = temp->next;
	}
	temp->text = text_temp;
}

void LinkedList::set_occurance (int pos, int occurance_temp)
{
	NodePtr temp = head;
	for (int i = 0; i < pos; i++)
	{
		temp = temp->next;
	}
	temp->occurance = occurance_temp;
}

void LinkedList::add (string text_temp)
{
	if (empty()) // If list is empty
	{
		head = new node;
		tail = head;
		head->next = NULL;
		head->prev = NULL;
		head->text = text_temp;
		head->occurance = 1;
	}
	else
	{
		NodePtr temp = tail;
		temp->next = new node;
		temp->next->next = NULL;
		temp->next->prev = temp;
		temp->next->text = text_temp;
		temp->next->occurance = 1;
		tail = temp->next;
	}
	list_size++;
}

void LinkedList::increment_occurance (int pos)
{
	NodePtr temp = head;
	for (int i = 0; i < pos; i++)
	{
		temp = temp->next;
	}
	temp->occurance = temp->occurance + 1;
}

void LinkedList::sort (int pos)
{
	NodePtr temp = head;
	for (int i = 0; i < pos; i++)
	{
		temp = temp->next;
	}

	// sort
	while (temp->prev != NULL)
	{
		if (temp->occurance > temp->prev->occurance)
		{
			//swap
			NodePtr prev = temp->prev;

			// fix head tail
			if (temp == tail && head == prev)
			{
				tail = prev;
				head = temp;
			}
			else if (temp == tail)
			{
				tail = prev;
			}
			else if (prev == head)
			{
				head = temp;
			}

			//swap
			// Fix the links of the nextious node, and the prev-prev node
			if (temp->next)
				temp->next->prev = prev;

			if (prev->prev)
				prev->prev->next = temp;

			// Relink the two nodes that should be swapped
			temp->prev = prev->prev;
			prev->prev = temp;

			prev->next = temp->next;
			temp->next = prev;

		}
		else
			break;
	}
}

void LinkedList::remove (int position)
{
	if ((empty()) || (position >= list_size))
		return;
	else if (head == tail)
	{
		delete head;
		head = NULL;
		tail = NULL;
	}
	else if (position == 0)
	{
		NodePtr temp = head->next;
		delete head;
		head = temp;
		if (head == NULL)
			tail = NULL;
		else
			head->prev = NULL;
	}
	else if (position == (list_size - 1))
	{
		NodePtr temp = tail->prev;
		delete temp->next;
		temp->next = NULL;
		tail = temp;
	}
	else
	{
		NodePtr temp = head;
		for (int i = 0; i < position; i++)
		{
			temp = temp->next;
		}
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		delete temp;
	}
	list_size--;
}

string LinkedList::get_text(int position)
{
	if ((empty()) || (position >= list_size))
		return "ERROR!\n";

	NodePtr temp = head;
	for (int i = 0; i < position; i++)
	{
		temp = temp->next;
	}
	return temp->text;
}

int LinkedList::get_occurance(int position)
{
	if ((empty()) || (position >= list_size))
		return -1;

	NodePtr temp = head;
	for (int i = 0; i < position; i++)
	{
		temp = temp->next;
	}
	return temp->occurance;
}

bool LinkedList::empty()
{
	return(head == NULL);
}
