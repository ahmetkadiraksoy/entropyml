#include <iostream>
#include <vector>

using namespace std;

class ExamplesVector
{
	public:
		ExamplesVector();
		ExamplesVector(string);
		int get_occurance(int);
		string get_text(int);
		int size();
		bool empty();
		void add(string);
		void remove(int);
		void set_text(int, string);
		void increment_occurance(int);
		void sort(int);
		void set_occurance(int, int);
		void clear();
		vector<string> get_item();
		void set_item(vector<string>);
	private:
		vector<string> item;
		vector<int> occurance;
};
