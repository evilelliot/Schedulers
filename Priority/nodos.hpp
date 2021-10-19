#ifndef nodos_hpp
#define nodos_hpp


class nodos{

  //codigo modular del nodo
  class node{

    int x;
    node *p;
    public:

    node(int n): x(n), p(nullptr){}
    int data() const {return x;}
    node *next() const {return p;}
    void next(node *q){p= q;}
  };
  
  //EndOfQueue y StartOfQueue reemplazan el Head y el Tail del codigo anterior.
  node *eoq; //final de la fila (head)
  node *soq; //inicio de la fila (tail)
  int cap, size;

  public:

  cola(int cap);
  ~cola();


  void enqueue(int x);
  int dequeue();
  void print();
                
  int getCapacity() const { return cap;}
  int getSize() const { return size;}

  bool isFull() const { return size== cap; }
  bool isEmpty() const { return size== 0;}


};
#endif