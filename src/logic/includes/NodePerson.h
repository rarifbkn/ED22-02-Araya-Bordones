#include "Person.h"
#ifndef NODEPERSON_H
#define NODEPERSON_H

class NodePerson{
private:
    Person person;
    NodePerson *next;
public:
    NodePerson(Person p);
    Person getPerson();
    void setPerson(Person p);
    NodePerson* getNext();
    void setNext(NodePerson *n);

    ~NodePerson();
};
#endif