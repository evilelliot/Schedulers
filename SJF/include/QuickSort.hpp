#ifndef QuickSort_hpp
#define QuickSort_hpp

#include "Node.hpp"

class QuickSort{
    public:
        static void swap(Node*, Node*);
        static void sort(Node*, int, int);
        static void show(Node*, int);
        static int separate(Node*, int, int);
        static int size(int data[]);
};

#endif