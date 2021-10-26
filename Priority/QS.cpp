#include "QS.hpp"
#include "nodos.hpp"
#include <iostream>
using namespace std;

void QS::swap(node *a, node *b){
  //Se rotan las pocisiones para actualizar los valores de prioridad
    node tmp = *a;
    *a = *b;
    *b = tmp;
}

int QS::separate(node* bucket, int low, int high) {
    int pivot = bucket[high].Prio;
    int i = low - 1;

    for (int x = low; x <= high - 1; x++) {
        if (bucket[x].Prio <= pivot) {
            i++;
            swap(&bucket[i], &bucket[x]);
        }
    }
    swap(&bucket[i + 1], &bucket[high]);
    return i + 1;
}

void QS::sort(node* bucket, int low, int high){
    
    if (low < high) {
        int part = separate(bucket, low, high);

        sort(bucket, low, part - 1);
        sort(bucket, part + 1, high);
    }

}

void QS::show(node* bucket, int size){
    for(int i = 0; i < size; i++){
      //imprime el array actualizado
        cout << "[" << i << "] Prioridad : " <<bucket[i].Prio<< endl;
    }
}

int QS::size(int* bucket) {
    return sizeof(bucket);
}