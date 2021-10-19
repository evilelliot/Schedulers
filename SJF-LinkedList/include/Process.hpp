/**
 * @file Process.hpp
 * 
 * @project SJF-Algorithm
 * 
 * @author Alberto Ocaranza
 * Contact: alt.ocaranza@gmail.com
 *
 */
#ifndef Process_hpp
#define Process_hpp

#include <string>
using namespace std;

class Process{
    private:
        string PID;
        int BT;
        Process *p;
    public:
        Process(string _PID, int _BT): PID(_PID), BT(_BT){}
        int getBT() const { return BT; }
        string getPID() const { return PID; }
        Process *next() const { return p; }
        void next(Process *q) { p = q; } 
};

#endif