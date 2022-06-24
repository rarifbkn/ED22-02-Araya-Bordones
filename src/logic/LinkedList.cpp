#include "includes/LinkedList.h"

LinkedList::LinkedList(){

}
NodePerson* LinkedList::getFirst(){
    return this->first;
}
bool LinkedList::isEmpty(){
    return this->first;
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
