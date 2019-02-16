#include <iostream>
#include <string>
#include "linkedlistarray.h"

LinkedListArray::LinkedListArray ()
{
	head2 = NULL;
}

int LinkedListArray::size()
{
	int size_temp = 0;
	for (NodePtr2 temp = head2; temp != NULL; temp = temp->next)
		size_temp++;
	return size_temp;
}

void LinkedListArray::clear ()
{
	//NEED TO CLEAR SUBITEMS
	NodePtr2 temp = head2;
	NodePtr2 temp2 = head2;

	while(temp != NULL)
	{
		temp2 = temp->next;
		delete temp;
		temp = temp2;
	}
	head2 = NULL;
}

NodePtr2 LinkedListArray::get_array_head()
{
	return head2;
}

void LinkedListArray::set_item (int pos, LinkedList text_temp)
{
	NodePtr2 temp = head2;
	for (int i = 0; i < pos; i++)
	{
		temp = temp->next;
	}
	temp->item = text_temp;
}

void LinkedListArray::add (LinkedList value_temp)
{
	if (empty()) // If list is empty
	{
		head2 = new node2;
		head2->next = NULL;
		head2->item = value_temp;
	}
	else
	{
		NodePtr2 temp;
		for (temp = head2; temp->next != NULL; temp = temp->next);
		temp->next = new node2;
		temp->next->next = NULL;
		temp->next->item = value_temp;
	}
}

void LinkedListArray::remove (int position)
{
	if ((empty()) || (position >= size()))
		return;
	else if (position == 0)
	{
		NodePtr2 temp = head2->next;
		delete head2;
		head2 = temp;
	}
	else if (position == (size() - 1))
	{
		NodePtr2 temp;
		for (temp = head2; temp->next->next != NULL; temp = temp->next);
		delete temp->next;
		temp->next = NULL;
	}
	else
	{
		NodePtr2 temp = head2;
		for (int i = 0; i < (position - 1); i++)
			temp = temp->next;
		NodePtr2 temp2 = temp->next;
		temp->next = temp->next->next;
		delete temp2;
	}
}

LinkedList LinkedListArray::get_item(int position)
{
	//if ((empty()) || (position >= size()))
		//return NULL;

	NodePtr2 temp = head2;
	for (int i = 0; i < position; i++)
		temp = temp->next;
	return temp->item;
}

bool LinkedListArray::empty()
{
	return(head2 == NULL);
}
