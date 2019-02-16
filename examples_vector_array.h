#include "examples_vector.h"

using namespace std;

class ExamplesVectorArray
{
	public:
		ExamplesVectorArray ();
		ExamplesVector get_item(int);
		int size();
		bool empty();
		void add(ExamplesVector);
		void remove(int);
		void set_item(int, ExamplesVector);
		void clear();
	private:
		vector<ExamplesVector> item2;
};
