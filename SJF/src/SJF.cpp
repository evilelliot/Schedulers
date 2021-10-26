#include "../include/SJF.hpp"
#include "../include/QuickSort.hpp"
#include <iostream>
using namespace std;

SJF::SJF(int x): size(x){
    this->bucket = new Node[size];
    this->awt    = 0;
    this->twt    = 0;
    // Leyendo los datos
    this->setData();
    // Ordenando los datos
    QuickSort::sort(this->bucket, 0, size - 1);
}
void SJF::scheduler(){
    this->waitingCalculator();
    this->print();
    gotoxy(60, y + 10);
    cout << "Tiempo de espera: " << this->twt << endl;
    gotoxy(60, y + 11);
    cout << "Tiempo de espera promedio: " << this->awt << endl;
}
// Ingresar datos
void SJF::setData(){
    y = 12;
    Node tmp;
    int _key  = 0;
    int _at = 0;
    string _data;
    for(int i = 0; i < this->size; i++){
        this->y = this->y + 2;
        gotoxy(60, y);
        cout << "["<<i<<"] Arrival time: "; cin >> _at;
        gotoxy(80, y);
        cout << "["<<i<<"] Burst time: "; cin >> _key;
        gotoxy(100, y);
        cout << "["<<i<<"] Data: "; cin >> _data;
        tmp = Node(_key, _at, _data);
        this->bucket[i] = tmp;
    }
}
// Calcular waiting times
void SJF::waitingCalculator(){
    int sum = 0;
    for(int i = 0; i < this->size; i++){
        // Guardar los waiting times
        int _key = this->bucket[i].bt;
        if(i == 0){
            this->bucket[i].setWT(_key);
            // cout << this->bucket[i].data << " " << "CWT: " << _key << " BT:" << this->bucket[i].bt << endl;
        }else{
            this->bucket[i].setWT(this->bucket[i - 1].bt + _key);
            // cout << this->bucket[i].data << " " << "CWT: " << this->bucket[i - 1].bt + _key <<" BT: " << this->bucket[i].bt << endl;
        }
        sum = this->bucket[i].wt;
        // cout << this->bucket[i].data << " " << this->bucket[i].bt << endl; 
    }
    this->twt = sum;
    this->awt = float(sum) / this->size;

    //cout << "Suma: " << sum << endl;
    //cout << "Prom: " << float(sum) / this->size << endl;
}
void SJF::print(){
    
    for(int i = 0; i < this->size; i++){
        this->y++;
        gotoxy(60, y + 2);
        cout << "["<<i<<"] Data: " << this->bucket[i].data;
        gotoxy(80, y + 2);
        cout << " WT: " << this->bucket[i].wt;
        gotoxy(90, y + 2);
        cout << " BT: " << this->bucket[i].bt << endl;
    }
}
void SJF::gotoxy(int x, int y){
    CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}
void SJF::clearSide(){
    for(int i = 0; i < 100; i++){
        gotoxy(60, i);
        cout << "                                                          ";
    }
}