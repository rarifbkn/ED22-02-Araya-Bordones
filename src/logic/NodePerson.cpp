#include "includes/NodePerson.h"

NodePerson ::NodePerson(Person p){
    this->persona = p;
    this->HIzq = nullptr;
    this->HDer = nullptr;
}
    
Person NodePerson::getPerson(){
    return this->persona;
}
NodePerson* NodePerson::getHIzq(){
    return this->HIzq;
}
NodePerson* NodePerson::getHDer(){
    return this->HDer;
}

