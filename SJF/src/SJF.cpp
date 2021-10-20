#include "../include/SJF.hpp"
#include "../include/QuickSort.hpp"
#include <iostream>
using namespace std;

SJF::SJF(int x): size(x){
    this->bucket = new Node[size];
    // Leyendo los datos
    this->setData();
    // Ordenando los datos
    QuickSort::sort(this->bucket, 0, size - 1);
}
void SJF::scheduler(){
    int wt = 0;
    for(int i = 0; i < this->size; i++){
        wt = wt + this->bucket[i].key; 
        cout << this->bucket[i].data << ": " << wt << endl;
    }
    cout << "Tiempo de espera: " << wt << endl;
    cout << "Tiempo de espera promedio: " << float(wt) / this->size << endl;
}
void SJF::setData(){
    Node tmp;
    int _key  = 0;
    string _data;
    for(int i = 0; i < this->size; i++){
        cout << "["<<i<<"] Burst time: "; cin >> _key;
        cout << "["<<i<<"] Data: "; cin >> _data;

        tmp = Node(_key, _data);
        this->bucket[i] = tmp;
    }
}
void SJF::print(){
    for(int i = 0; i < this->size; i++){
        cout << "["<<i<<"] Key: " << this->bucket[i].key << " Data: " << this->bucket[i].data << endl;
    }
}