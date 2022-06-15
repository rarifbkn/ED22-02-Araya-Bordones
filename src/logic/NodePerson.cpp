#include "includes/NodePerson.h"

NodePerson::NodePerson(){

}

NodePerson ::NodePerson(Person* p){
    this->person = p;
    this->next = nullptr;
}
Person* NodePerson::getPerson(){
    return this->person;
}
void NodePerson::setPerson(Person *p){
    this->person =p;
}
NodePerson* NodePerson::getNext(){
    return this->next;
}
void NodePerson::setNext(NodePerson *n){
    this->next = n;
}
NodePerson::~NodePerson(){

}