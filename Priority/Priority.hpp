#ifndef Priority_hpp
#define Priority_hpp

#include "nodos.hpp"
#include <string>

using namespace std;

class Priority {
	int size;
	int twt;
	float awt;
	node* bucket;
	public:
		Priority(int);
		Priority() {}

		void scheduler();
		void setData();
		void print();
		void waitingCalculator();
};

#endif
