#include "NodePerson.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <functional>
#include <iterator>
#include <limits>
#include <memory>
#include <vector>


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