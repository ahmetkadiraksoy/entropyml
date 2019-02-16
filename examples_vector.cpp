#include <iostream>
#include <string>
#include <vector>
#include "examples_vector.h"

ExamplesVector::ExamplesVector()
{
}

ExamplesVector::ExamplesVector(string text_temp)
{
	add(text_temp);
}

int ExamplesVector::size()
{
	return item.size();
}

void ExamplesVector::clear()
{
	vector<string>().swap(item);
	vector<int>().swap(occurance);
}

void ExamplesVector::set_text(int pos, string text_temp)
{
	item.at(pos) = text_temp;
}

void ExamplesVector::set_occurance(int pos, int occurance_temp)
{
	occurance.at(pos) = occurance_temp;
}

void ExamplesVector::add(string text_temp)
{
	item.push_back(text_temp);
	occurance.push_back(1);
}

void ExamplesVector::remove(int position)
{
	item.erase(item.begin() + position);
	occurance.erase(occurance.begin() + position);
}

void ExamplesVector::increment_occurance(int position)
{
	occurance.at(position) = occurance.at(position) + 1;
}

vector<string> ExamplesVector::get_item()
{
	return item;
}

void ExamplesVector::set_item (vector<string> input)
{
	item = input;
}

void ExamplesVector::sort (int pos)
{
	// Sort
	if (pos > 0)
	{
		for (int i = (pos - 1); i >= 0; i--)
		{
			if (occurance.at(pos) > occurance.at(i))
			{
				int node_temp = occurance.at(pos);
				occurance.at(pos) = occurance.at(i);
				occurance.at(i) = node_temp;

				string text_temp = item.at(pos);
				item.at(pos) = item.at(i);
				item.at(i) = text_temp;

				pos = i;
			}
			else
				break;
		}
	}
}

string ExamplesVector::get_text(int position)
{
	if ((item.empty()) || (position >= item.size()))
		return "ERROR!\n";

	return item.at(position);
}

int ExamplesVector::get_occurance(int position)
{
	if ((occurance.empty()) || (position >= occurance.size()))
		return -1;

	return occurance.at(position);
}

bool ExamplesVector::empty()
{
	int temp_size = item.size();
	if (temp_size == 0)
		return true;
	else
		return false;
}
