#include "QuickSort.hpp"
#include "nodos.hpp"
#include <iostream>
using namespace std;

void QuickSort::swap(node *a, node *b){
  //Se rotan las pocisiones para actualizar los valores de prioridad
    node tmp = *a;
    *a = *b;
    *b = tmp;
}

int QuickSort::separate(node* bucket, int low, int high) {
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

void QuickSort::sort(node* bucket, int low, int high){
    
    if (low < high) {
        int part = separate(bucket, low, high);

        sort(bucket, low, part - 1);
        sort(bucket, part + 1, high);
    }

}

void QuickSort::show(node* bucket, int size){
    for(int i = 0; i < size; i++){
      //imprime el array actualizado
        cout << "[" << i << "] Prioridad : " <<bucket[i].Prio<< endl;
    }
}

int QuickSort::size(int* bucket) {
    return sizeof(bucket);
}