#include "includes/LinkedList.h"

LinkedList::LinkedList(){

}
LinkedList::LinkedList(NodePerson* first){
    this->first = first;
}

NodePerson* LinkedList::getFirst(){
    return this->first;
}
void LinkedList::setNodo(NodePerson* n){
    this->first = n;
}
void LinkedList::insert(string identidad){ //last insert
    Person* p  = new Person();
    NodePerson* n = new NodePerson(p);
    NodePerson* aux = first;
    if(aux != nullptr){
        while(aux->getNext()!= nullptr){ //recorre la lista hasta el ultimo
        aux = aux->getNext();
    } // si el sgte es null se rompe
    aux->setNext(n);
    }    
}
int LinkedList::cantPersonas(){
    int cantPersonas=0;
    NodePerson* aux = this->first;
    while(aux != nullptr){
        cantPersonas++;
        aux = aux->getNext();
    }
    return cantPersonas;
}
LinkedList::~LinkedList(){

}