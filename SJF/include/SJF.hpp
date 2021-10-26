#ifndef SJF_hpp
#define SJF_hpp

#include "../include/Node.hpp"
#include <string>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;

class SJF{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD CursorPosition;
    int size;
    int twt;
    float awt;
    int y = 0;
    Node *bucket;
    public:
        SJF(int);
        SJF(){}
        // Scheduler
        void scheduler();
        // Setters
        void setData();
        // Testing
        void print();
        // Calcular wt
        void waitingCalculator();
        // gotoxy
        void gotoxy(int, int);
        // clear screen
        void clearSide();
};

#endif