#ifndef Robin_hpp
#define Robin_hpp

#include "Node.hpp"
#include <string>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;

class Robin{    
    private:
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD CursorPosition;
        Node *head = NULL;
        int size;
        float quantumm;
        int y;
    public:
        Robin(int, float);      // Queue size | Quantumm
        void push(string, int); // PID | BT 
        void pop(string);
        void process(int);
        // Gotoxy
        void gotoxy(int, int);
        // Clear
        void clearSide();
};

#endif