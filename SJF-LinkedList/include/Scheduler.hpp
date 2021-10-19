/**
 * @file Scheduler.hpp
 * 
 * @project SJF-Algorithm
 * 
 * @author Alberto Ocaranza
 * Contact: alt.ocaranza@gmail.com
 *
 */
#ifndef Scheduler_hpp
#define Scheduler_hpp

#include "Process.hpp"
#include <iostream>
#include <string>
using namespace std;

class Scheduler{
    private:
        // End-of-schedule | Start-of-schedule
        Process *eos;
        Process *sos;
        int _size, _capacity;
    public:
        // Constructor & destructor
        Scheduler(){}
        Scheduler(int);
        ~Scheduler();
        // Procesos de enqueue y dequeue
        void enqueue(int, string);
        bool dequeue();
        // Procesar la lista actual
        void scheduleProcess();
        // Getters
        int getCapacity() const { return _capacity; }
        int getSize() const { return _size; }
        // Operaciones de ordenamiento
        void sortSchedule();
        // Operaciones de control
        bool isEmpty() const { return _size == 0; }
        bool isFull() const { return _size == _capacity; }
        // Testing
        void peek();
        void print();
};
        

#endif