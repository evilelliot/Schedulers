#ifndef Node_hpp
#define Node_hpp

#include <string>
using namespace std;

class Node{
    public:
        Node(){}
        Node(int bt, int at, string d): bt(bt), at(at), data(d){}
        void setWT(int wt);
        int bt;
        int at;
        int wt;
        string data;
};

#endif