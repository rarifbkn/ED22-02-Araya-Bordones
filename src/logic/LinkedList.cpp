#include "includes/LinkedList.h"

LinkedList::LinkedList(){

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
bool LinkedList::isEmpty(){
    return this->first;
}

NodePerson* LinkedList::getFirst(){
    return this->first;
}

LinkedList::~LinkedList(){
    this->first->~NodePerson();
}


