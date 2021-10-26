#include "Priority.hpp"
#include "QS.hpp"
#include "nodos.hpp"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;

Priority::Priority(int x) : size(x) {

	bucket = new node[size];
	awt = 0;
	twt = 0;
	setData();
	QS::sort(bucket, 0, size - 1);
	y = 12;
}

void Priority::scheduler() {
	waitingCalculator();
	print();
	gotoxy(60, y + 2);
	cout << " Tiempo de Espera : " << twt << endl;
	gotoxy(60, y + 4);
	cout << "Tiempo Promedio : " << awt << endl;
}

void Priority::setData() {
	node tmp;
	int bt = 0;
	int Prio = 0;
	for (int i = 0; i < size; i++) {
		gotoxy(60, y);
		cout << "["<< i << "] Burst Time : "; cin >> bt;
		gotoxy(80, y);
		cout << "[" << i << "] Priority : "; cin >> Prio;
		tmp = node(bt, Prio);
		bucket[i] = tmp;
		y++;
	}
}

void Priority::waitingCalculator() {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		int bt = bucket[i].BT;
		if (i == 0) {
			bucket[i].setWT(bt);
		}
		else {	
			bucket[i].setWT(bucket[i - 1].BT + bt);
		}
		sum = bucket[i].WT;
	}

	twt = sum;
	awt = float(sum) / size;

}
void Priority::print() {
	for (int i = 0; i < size; i++) {
		y++;
		gotoxy(60, y);
		cout << "[" << i << "] Priority : " << bucket[i].Prio << endl;
		gotoxy(80, y);
		cout << "WT : " << bucket[i].WT;
		gotoxy(100, y);
		cout << "BT : " << bucket[i].BT << endl;
	}
}
void Priority::gotoxy(int x, int y){
    CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}
void Priority::clearSide(){
    for(int i = 0; i < 100; i++){
        gotoxy(60, i);
        cout << "                                                          ";
    }
}