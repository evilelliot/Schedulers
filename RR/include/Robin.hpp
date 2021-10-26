#ifndef Robin_hpp
#define Robin_hpp

#include "Node.hpp"
#include <string>
using namespace std;

class Robin{    
    private:
        Node *head = NULL;
        int size;
        float quantumm;
    public:
        Robin(int, float);      // Queue size | Quantumm
        void push(string, int); // PID | BT 
        void pop(string);
        void process(int);
};

#endif