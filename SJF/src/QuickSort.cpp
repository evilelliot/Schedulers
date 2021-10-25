#include "../include/QuickSort.hpp"
#include "../include/Node.hpp"
#include <iostream>
using namespace std;

void QuickSort::swap(Node *a, Node *b){
    Node t = *a;
    *a    = *b;
    *b    = t;
}
void QuickSort::sort(Node* bucket, int _low, int _high){
    // Lowest to greatest number order
    if(_low < _high){
        // Creating a partition
        int _partiton = separate(bucket, _low, _high);

        sort(bucket, _low, _partiton - 1);
        sort(bucket, _partiton + 1, _high);
    }
}
int QuickSort::separate(Node* bucket, int _low, int _high){
    int pivot = bucket[_high].bt;
    // Index of smallest element
    int i     = _low - 1;
    // Traversing array for comparision
    for(int x = _low; x <= _high - 1; x++){
        if(bucket[x].bt <= pivot){
            i++;
            swap(&bucket[i], &bucket[x]);
        }
    }
    // Swap on the next element before smallest element
    swap(&bucket[i + 1], &bucket[_high]);
    return i + 1;
}
void QuickSort::show(Node *bucket, int n){
    for(int i = 0; i < n; i++){
        cout << "["<<i<<"]"<<bucket[i].at << " Data: " << bucket[i].data <<endl;
    }
}
int QuickSort::size(int bucket[]){
    return sizeof(bucket);
}