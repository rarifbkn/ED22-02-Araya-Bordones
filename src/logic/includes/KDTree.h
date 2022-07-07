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
    NodePerson* insertar(vector<NodePerson> personas, int prof);
    void eliminar(int clave);
};