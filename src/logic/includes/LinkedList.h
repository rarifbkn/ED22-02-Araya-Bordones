#ifndef TALLER_LINKEDLIST_H
#define TALLER_LINKEDLIST_H
#include "NodePerson.h"

class LinkedList{
    private:
        NodePerson* first;
    public:
        LinkedList();
        NodePerson* getFirst();
        void insert(NodePerson* n);
        Person getPersonI(int i);
        bool isEmpty();
        ~LinkedList();
};
#endif