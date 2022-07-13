#include "NodePerson.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

class KDTree{
    private:
    NodePerson *raiz;

    public:
    KDTree();
    NodePerson* getRaiz();
    void printInOrder(NodePerson* raiz);
    Person* insertar(vector<Person> personas, int prof);
    void eliminar(int clave);
};