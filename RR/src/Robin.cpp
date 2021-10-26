#include "../include/Robin.hpp"
#include <string>
#include <iostream>
using namespace std;


Robin::Robin(int _size, float _q): size(_size), quantumm(_q){
    int tmp_bt = 0;
    string tmp_pid;
    for(int i = 0; i < this->size; i++){
        cout << "[" << i << "]BT: "; cin >> tmp_bt;
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
  float avg_tat;

  while (head != NULL){
  {
    temp->rt = temp->rt - t;
    c = c + t;
    if (temp->rt <= 0){
      c = c + temp->rt;
      cout << temp->name; 
      cout << " BT: " << temp->tm;
      cout << " TAT: " << c;
      cout << " WT: " << c - temp->tm << endl;
      avg_tat = avg_tat + c - temp->tm;
      pop(temp->name);
      if (temp->next == temp){
        break;
      }
    }
    temp = temp->next;
  }
  }
  cout << size << endl;
  cout << "AVG TAT: " << avg_tat / size << endl;
}
