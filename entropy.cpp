#include "linkedlistarray.h"
#include "examples_vector_array.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

vector<string> split(string, string);
void read_input_file(string, ExamplesVector&);
void find_entropies(ExamplesVector&, bool, int);
string double_to_string (double);

int main (int argc, char* argv[])
{
	unsigned int number_of_attributes = 0; // holds the number of attributes within the file
	ExamplesVector examples; // contains example set from the file

	read_input_file(string(argv[1]), examples);
	cout << "Number of examples: " <<examples.size() <<endl;

	number_of_attributes = split(examples.get_text(0), ",").size() - 1;
	cout << "Number of attributes: " <<number_of_attributes <<endl;
	cout << endl;

	find_entropies(examples, true, number_of_attributes);
}

// Splits the provided string variable by the delimiter into an array
vector<string> split(string line, string delimiter)
{
	vector<string> tokens;
	char* s = new char[line.size() + 1];
	memcpy(s, line.c_str(), line.size() + 1);
	const char *token = strtok(s, delimiter.c_str());

	while (token != NULL)
	{
		tokens.push_back(token);
		token = strtok(NULL, delimiter.c_str());
	}

	return tokens;
}

void read_input_file(string input_file_path, ExamplesVector& examples)
{
	string readline;
	ifstream in_file;
	in_file.open(input_file_path.c_str());

	while (in_file >> readline) // for each line in the file
	{
		examples.add(readline);
	}

	in_file.close();
}

string double_to_string (double input)
{
	std::ostringstream strs;
	strs << input;
	std::string str = strs.str();

	return str;
}

void find_entropies(ExamplesVector& examples, bool verbose, int number_of_attributes)
{
	// Find the number of unique classes
	LinkedList unique_classes;
	for (int i = 0; i < examples.size(); i++)
	{
		string example_class = split(examples.get_text(i), ",")[number_of_attributes]; // get the class from example j
		bool exists = false;
		for (int j = 0; j < unique_classes.size(); j++)
		{
			if (unique_classes.get_text(j) == example_class)
			{
				exists = true;
				break;
			}
		}

		if (!exists)
			unique_classes.add(example_class);
	}
	int no_of_classes = unique_classes.size();

	ExamplesVector entropies; // holds entropy values for features

	for (int i = 0; i < number_of_attributes; i++) // for each attribute
	{
		// Print progress
		if (verbose)
			cout << "\r" << "Attribute " << (i+1) << "/" << number_of_attributes << flush;

		LinkedList instances; // holds unique instances for each attribute
		LinkedListArray instance_classes; // holds unique classes for each attribute

		for (int j = 0; j < examples.size(); j++) // for each example
		{
			string example_attribute = split(examples.get_text(j), ",")[i]; // get the attribute value from example j
			string example_class = split(examples.get_text(j), ",")[number_of_attributes]; // get the class from example j

			// if instance does not exist in list, add it. if exists, increment occurance
			bool instance_exists = false;
			for (int k = 0; k < instances.size(); k++) // loop through the instances
			{
				if (instances.get_text(k) == example_attribute) // if current instance is found
				{
					instance_exists = true;
					instances.increment_occurance(k); // increment the instance occurance

					// If the class of the current example exists, increment it
					bool class_exists = false;
					for (int l = 0; l < instance_classes.get_item(k).size(); l++)
					{
						if (instance_classes.get_item(k).get_text(l) == example_class)
						{
							class_exists = true;
							LinkedList item = instance_classes.get_item(k);
							item.increment_occurance(l);
							instance_classes.set_item(k, item);

							break;
						}
					}

					// If the class of the current example does not exist, add it
					if (!class_exists)
					{
						LinkedList item = instance_classes.get_item(k);
						item.add(example_class);
						instance_classes.set_item(k, item);
					}

					break;
				}
			}

			if (!instance_exists)
			{
				instances.add(example_attribute); // add instance

				// Add class
				LinkedList item;
				item.add(example_class);
				instance_classes.add(item);
			}
		}

		double entropy = 0;
		for (int j = 0; j < instances.size(); j++)
		{
			double without_rate = 0;
			for (int k = 0; k < instance_classes.get_item(j).size(); k++)
			{
				double term = instance_classes.get_item(j).get_occurance(k)/((double)instances.get_occurance(j));
				without_rate = without_rate + ((-1) * term * (log (term)/log (no_of_classes)));
			}
			without_rate = without_rate * (instances.get_occurance(j)/((double)examples.size()));
			entropy = entropy + without_rate;
		}
		cout << ": " << entropy << endl;
		entropies.add(double_to_string(entropy));
	}
}
