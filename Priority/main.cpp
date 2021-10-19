#include "bubble.hpp"
#include <iostream>
using namespace std;

void leer(char datos[], int tiempo[], int prioridad[]){
  //5 seran los valores que serán ingresados para las pruebas
 for(int i = 0; i <5; i++){
   cout<<"["<<datos[i]<<"] Ingresar tiempo :  ";
   cin>>tiempo[i];
   cout<<"["<<datos[i]<<"] Ingresar prioridad (del 1 al 5) :  ";
   cin>>prioridad[i];
   //Flag en caso de que se ingrese un numero que no este dentro del parametro
   if(prioridad[i]>5 || prioridad[i]<1){
     cout<<"Valor no Valido !"<<endl;
     //**
     exit(EXIT_FAILURE);
    }
  }
}

//** funcion de la ejecucion de datos, hará falta primero implementar los nodos antes de esta funcion.

int main() {
  char datos[5] = {'A','B','C','D','E'};
  int tiempo[5];
  int prioridad[5];
  
  //Se llama la funcion para leer 
  leer(datos,tiempo,prioridad);

  //Se hace el acomodo
  bubble::sort(prioridad, 5);

  for(int i=0;i<5;i++){
    cout<<"["<<datos[i]<<"]  "<<tiempo[i]<<"  "<<prioridad[i]<<endl;
  }
  //la funcion de bubble funciona de manera correcta, sin embargo no está acorde a lo requerido debido a que solo se cambia el array de la prioridad, no del proceso o el tiempo de ejecucion, se implementara una lista enlazada con nodos para soluionar este problema.

  //bubble::show(prioridad, 5);
}