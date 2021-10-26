/**
 * @file Scheduler.cpp
 * 
 * @project FIFO Algorithm
 * 
 * @author Alberto Ocaranza
 * Contact: alt.ocaranza@gmail.com
 *
 */
#include "../include/Process.hpp"
#include "../include/Scheduler.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;
// Constructor
Scheduler::Scheduler(int c): _capacity(c){
    this->_size = 0;
    this->eos = NULL;
    this->sos = NULL;
}
// Destructor
Scheduler::~Scheduler(){
    while(!isEmpty()){
        dequeue();
    }   
}
// Enlista procesos
void Scheduler::enqueue(int bt, string pid){
    // Precondición para controlar si está llena
    if(isFull()){ 
        cout << "No se puede enlistar un proceso nuevo." << endl;
    }else{
        // Un puntero temporal para guardar los datos del nuevo nodo
        Process *tmp = new Process(pid, bt);
        tmp->next(NULL); // Su puntero next se guarda en NULL porque no hay datos mas allá de el
        // Revisamos si es el primer dato ingresado
        if(getSize() == 0){
            // Si es el primer dato, head y tail es lo mismo
            eos = tmp;
            sos = tmp;
        }else{
            // Si no, hacemos que el next head sea el nuevo dato
            eos->next(tmp);
            eos = tmp;
        }
        // Aumentamos el tamaño +1
        _size++;
    }
}
bool Scheduler::dequeue(){
    // Precondición para controlar si esta vacía
    if(isEmpty()){
        cout << "Empty process list " << endl;
        return false; // Retornamos falso
    }else{
        // Si solo existe un dato en la lista, entonces head y tail ahora son nulos
        // y borramos head
        if(getSize() == 1){
            delete sos;
            sos = NULL;
            eos = NULL;

            _size = 0; 
        }else{
            // Hacemos un temporal de head
            Process *tmp = sos;
            // Hacemos que head ahora sea igual a su next
            sos = sos->next(); 
            // Borramos el temporal
            delete tmp;
            // Decrementamos el size
            _size--;
        }
        return true;
    }
}
void Scheduler::scheduleProcess(){
    this->clearSide();
    int wt = 0; // Waiting time
    int y = 7;
    // Precondición para controlar si esta vacía
    if(isEmpty()){
        cout << "Cannot print an empty schedule list" << endl;
    }else{
        // Hacemos un head temporal para no modificar el original
        Process *tmp_sos = sos;
        // Mientras head no sea null ejectuamos el algoritmo de scheduler
        while(tmp_sos != NULL){
            y = y + 1;
            // Sumamos el tiempo de espera original mas el proceso actual
            wt = wt + tmp_sos->getBT();
            // Imprimimos los datos
            gotoxy(60, y);
            cout << left << "PID: " << tmp_sos->getPID();
            gotoxy(80, y);
            cout << left << " WT: " << wt << endl;
            // Cambiamos al next
            tmp_sos = tmp_sos->next();
        }   
        gotoxy(60, y + 3);
        cout << "_______________________________________" << endl;
        gotoxy(60, y + 4);
        cout << "Process count: " << getSize() << endl;
        gotoxy(60, y + 5);
        cout << "Average Wait Time: " << wt / float(getSize()) << endl;
        gotoxy(60, y + 6);
        cout << "Total Wait Time: " << wt << endl;
        cout << endl;
        // Free tmp_sos space
        delete tmp_sos;
    }
}
void Scheduler::peek(){
    cout << eos->getPID() << endl;
    cout << eos->getBT() << endl;
} 
void Scheduler::gotoxy(int x, int y){
    CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}
void Scheduler::clearSide(){
    for(int i = 0; i < 100; i++){
        gotoxy(60, i);
        cout << "                                                          ";
    }
}