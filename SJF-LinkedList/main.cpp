/**
 * @file main.cpp
 * 
 * @project SJF-Algorithm
 * 
 * @author Alberto Ocaranza
 * Contact: alt.ocaranza@gmail.com
 *
 */
#include "include/Scheduler.hpp"
#include "include/Process.hpp"
#include <iostream>
using namespace std;
// Prototypes
void driver();
int main(){ 
    driver();
    return 0;
}
void driver(){
    system("clear");
    int n = 0;
    int tmp_bt = 0;
    string tmp_pid;
    cout << "Tamaño de la lista: "; cin >> n;
    system("clear");
    Scheduler sch(n);
    // Ingresar datos
    for(int i = 0; i < n; i++){
        cout << "[" << i+1 << "] Set PID: "; cin >> tmp_pid;
        cout << "[" << i+1 << "] Set BT:  "; cin >> tmp_bt;
        sch.enqueue(tmp_bt, tmp_pid); 
    }
    sch.scheduleProcess();
}