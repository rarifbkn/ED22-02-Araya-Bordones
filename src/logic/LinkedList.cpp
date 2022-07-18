#include "includes/LinkedList.h"

LinkedList::LinkedList(){

}
NodePerson* LinkedList::getFirst(){
    return this->first;
}
bool LinkedList::isEmpty(){
    return this->first;
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
