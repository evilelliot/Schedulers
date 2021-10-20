#include "include/SJF.hpp"
#include <iostream>
using namespace std;


int main(){
    int size = 0;
    cout << "Tamaño de lista: "; cin >> size;
    // Inicializando la lista
    SJF sch(size);
    cout << "________________________________" << endl;
    sch.scheduler();
    // sch.print();
    return 0;
}