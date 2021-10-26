#include "Priority.hpp"
#include "QuickSort.hpp"
#include "nodos.hpp"
#include <iostream>

using namespace std;

Priority::Priority(int x) : size(x) {

	bucket = new node[size];
	awt = 0;
	twt = 0;
	setData();
	QuickSort::sort(bucket, 0, size - 1);
}

void Priority::scheduler() {
	waitingCalculator();
	print();
	cout << " Tiempo de Espera : " << twt << endl;
	cout << "Tiempo Promedio : " << awt << endl;
}

void Priority::setData() {
	node tmp;
	int bt = 0;
	int Prio = 0;
	for (int i = 0; i < size; i++) {
		cout << "["<< i << "] Burst Time : "; cin >> bt;
		cout << "[" << i << "] Priority : "; cin >> Prio;
		tmp = node(bt, Prio);
		bucket[i] = tmp;
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
		cout << "[" << i << "] Priority : " << bucket[i].Prio << endl;
		cout << "WT : " << bucket[i].WT;
		cout << "BT : " << bucket[i].BT << endl;
	}
}