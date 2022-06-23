#ifndef TALLER_LINKEDLIST_H
#define TALLER_LINKEDLIST_H
#include "NodePerson.h"

class LinkedList{
private:
    NodePerson *first;

public:
    LinkedList();
    LinkedList(NodePerson& first);
    NodePerson& getFirst();
    void setNodo(NodePerson& n);
    void insert(string identidad);
    int cantPersonas();
    ~LinkedList();
    
};

#endif