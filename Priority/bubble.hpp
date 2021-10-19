#ifndef bubble_hpp
#define bubble_hpp

class bubble{
    
    public:
        //Swap será para la rotacion de valores del array
        static void swap(int*, int*);
        //Sort será el que hara el ordenamiento de menor a mayor o viceversa
        static void sort(int*, int);
        //Show actualizá el resultado final del acomodo
        static void show(int*, int);
};


#endif