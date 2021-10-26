#include "../include/Robin.hpp"
#include <string>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;


Robin::Robin(int _size, float _q): size(_size), quantumm(_q){
    int tmp_bt = 0;
    string tmp_pid;

    y = 9;
    for(int i = 0; i < this->size; i++){
        y++;
        gotoxy(60, y);
        cout << "[" << i << "]BT: "; cin >> tmp_bt;
        gotoxy(80, y);
        cout << "PID: "; cin >> tmp_pid;
        this->push(tmp_pid, tmp_bt);
    }
    this->process(this->quantumm);
}

void Robin::push(string _pid, int _bt){
    Node *nn = new Node;
    nn->name = _pid;
    nn->tm = _bt;
    nn->rt = nn->tm;

    if (head == NULL){
        head = nn;
        head->next = head;
    }else{
      Node *temp = head;
      while (temp->next != head){
        temp = temp->next;
      }
      nn->next = temp->next;
      temp->next = nn;
    }
}
void Robin::pop(string x){
  Node *p = NULL;
  Node *temp = head;

  if (head->name == x){
    while (temp->next != head){
      temp = temp->next;
    }
    p = head;
    temp->next = head->next;
    head = head->next;
    delete p;
  }else{
    while (temp->name != x){
      p = temp;
      temp = temp->next;
    }
    p->next = temp->next;
    delete temp;
  }
}
void Robin::process(int t){
  Node *temp = head;
  int c = 0, i = 0;
  float avg_tat = 0;
  y = y + 4;
  while (head != NULL){
  {
    temp->rt = temp->rt - t;
    c = c + t;
    if (temp->rt <= 0){
      y++;
      c = c + temp->rt;
      gotoxy(60, y);
      cout << temp->name; 
      gotoxy(75, y);
      cout << " BT: " << temp->tm;
      gotoxy(85, y);
      cout << " TAT: " << c;
      gotoxy(95, y);
      cout << " WT: " << c - temp->tm << endl;
      gotoxy(105, y);
      pop(temp->name);
      if (temp->next == temp){
        break;
      }
    }
    temp = temp->next;
  }
  }
}
void Robin::gotoxy(int x, int y){
  CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}
void Robin::clearSide(){
    for(int i = 0; i < 100; i++){
        gotoxy(60, i);
        cout << "                                                          ";
    }
}