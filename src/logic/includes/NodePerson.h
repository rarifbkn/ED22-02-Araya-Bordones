
#ifndef NODEPERSON_H
#define NODEPERSON_H
#include "Person.h"

class NodePerson{
private:
    Person persona;
    NodePerson *HIzq;
    NodePerson *HDer;
public:
    NodePerson(Person p);
    Person getPerson();
    NodePerson* getHDer();
    NodePerson* getHIzq();
};
#endif