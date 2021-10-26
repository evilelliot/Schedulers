#ifndef QuickSort_hpp
#define QuickSort_hpp

#include "nodos.hpp"

class QuickSort{
    
    public:
        //Swap será para la rotacion de valores del array
        static void swap(node*, node*);
        //Sort será el que hara el ordenamiento de menor a mayor o viceversa
        static void sort(node*, int, int);
        //Show actualizá el resultado final del acomodo
        static void show(node*, int);

        static int separate(node*, int, int);
        static int size(int* data);
};


#endif