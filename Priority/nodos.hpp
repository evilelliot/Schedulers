#ifndef nodos_hpp
#define nodos_hpp

#include <string>
using namespace std;

  //codigo modular del nodo
class node{
    public:
        node(){}
        node(int x, int y): BT(x), Prio(y){}
        void setWT(int wt);
        int BT;
        int Prio;
        int WT;
  };  
#endif