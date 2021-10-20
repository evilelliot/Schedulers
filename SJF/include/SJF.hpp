#ifndef SJF_hpp
#define SJF_hpp

#include "../include/Node.hpp"
#include <string>
using namespace std;

class SJF{
    int size;
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
};

#endif