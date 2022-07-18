#ifndef TALLER_LINKEDLIST_H
#define TALLER_LINKEDLIST_H
#include "NodePerson.h"

class LinkedList{
    private:
        NodePerson* first;
    public:
        LinkedList();
        NodePerson* getFirst();
        void insert(Person &p);
        bool isEmpty();
        ~LinkedList();
};
#endif