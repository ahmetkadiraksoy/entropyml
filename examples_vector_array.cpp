#include "examples_vector_array.h"

ExamplesVectorArray::ExamplesVectorArray()
{
}

int ExamplesVectorArray::size()
{
	return item2.size();
}

void ExamplesVectorArray::clear()
{
	item2.clear();
}

void ExamplesVectorArray::set_item(int pos, ExamplesVector text_temp)
{
	item2.at(pos) = text_temp;
}

void ExamplesVectorArray::add (ExamplesVector value_temp)
{
	item2.push_back(value_temp);
}

void ExamplesVectorArray::remove (int position)
{
	item2.erase(item2.begin() + position);
}

ExamplesVector ExamplesVectorArray::get_item(int position)
{
	return item2.at(position);
}

bool ExamplesVectorArray::empty()
{
	int size_temp = item2.size();
	if (size_temp == 0)
		return true;
	else
		return false;
}
