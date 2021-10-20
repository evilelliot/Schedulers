#ifndef Node_hpp
#define Node_hpp

#include <string>
using namespace std;

class Node{
    public:
        Node(){}
        Node(int x, string d): key(x), data(d){}
        int key;
        string data;
};

#endif