#ifndef Priority_hpp
#define Priority_hpp

#include "nodos.hpp"
#include <string>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;

class Priority {
	int size;
	int twt;
	float awt;
	int y;
	node* bucket;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD CursorPosition;
	public:
		Priority(int);
		Priority() {}

		void scheduler();
		void setData();
		void print();
		void waitingCalculator();
		void gotoxy(int, int);
		void clearSide();
};

#endif
