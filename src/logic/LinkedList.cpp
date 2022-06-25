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
void LinkedList::insert(NodePerson* n){
    if(isEmpty()){
        this->first = n;    
    }else{
        NodePerson* aux = first;
        while(aux->getNext() != nullptr){
            aux = aux->getNext();
        }
        aux->setNext(n);
    }
}
LinkedList::~LinkedList(){
    this->first->~NodePerson();
}
