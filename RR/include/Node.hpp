/**
 * @Author: Alberto Ocaranza
 * 
 * @program Node class definition
 * 
*/
#ifndef Node_hpp
#define Node_hpp

#include <string>
using namespace std;

class Node{
    public:
    string name;
    int tm;
    int rt;
    float avg_tat;
    Node *next;
};

#endif