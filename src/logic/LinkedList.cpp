#include "includes/LinkedList.h"

LinkedList::LinkedList(){

}
NodePerson* LinkedList::getFirst(){
    return this->first;
}
bool LinkedList::isEmpty(){
    return this->first;
}
Person LinkedList::getPersonI(int i){
    int a = 0;
    NodePerson* aux = this->first;
    while(aux->getNext() != nullptr){
    if(a == i){
        return aux->getPerson();
    }
    aux = aux->getNext();
    a++;
    }
}
void LinkedList::insert(Person& p){
    NodePerson n = NodePerson(p);
    NodePerson* nodoptr = &n;
    if(isEmpty()){
        this->first = nodoptr;    
    }else{
        NodePerson* aux = first;
        while(aux->getNext() != nullptr){
            aux = aux->getNext();
        }
        aux->setNext(nodoptr);
    }
    

}
LinkedList::~LinkedList(){
    this->first->~NodePerson();
}
