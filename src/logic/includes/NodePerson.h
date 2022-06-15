#ifndef TALLER_NODEPERSON_H
#define TALLER_NODEPERSON_H
#include "Person.h"

class NodePerson{
private:
    Person *person;
    NodePerson *next;
public:
    NodePerson();
    NodePerson(Person* p);
    Person *getPerson();
    void setPerson(Person *p);
    NodePerson *getNext();
    void setNext(NodePerson *n);

    ~NodePerson();
};

#endif