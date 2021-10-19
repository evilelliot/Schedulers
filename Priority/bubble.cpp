#include "bubble.hpp"
#include <iostream>
using namespace std;

void bubble::swap(int *a, int *b){
  //Se rotan las pocisiones para actualizar los valores de prioridad
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
void bubble::sort(int *data, int size){
  //el primer for es recorre todo el array, el segundo es el que revisa y acomoda de menor a mayor
  for(int i = 0; i < size - 1; i++){
    for(int j = 0; j < size - i - 1; j++){
      if(data[j] > data[j+1]){
        //Se hace el cambio de pocision de las prioridades 
        swap(&data[j], &data[j+1]);
      }
    }
  }
}
//1, 2, 3, 4, 6
void bubble::show(int *data, int size){
    for(int i = 0; i < size; i++){
      //imprime el array actualizado
        cout << "[" << i << "]  " << data[i] << endl;
    }
}