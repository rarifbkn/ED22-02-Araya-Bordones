#include "includes/KDTree.h"


KDTree::KDTree(){
    
}

NodePerson* KDTree::getRaiz(){
    return this->raiz;
}

void KDTree::printInOrder(NodePerson* raiz){
    if(raiz){
       printInOrder(raiz->getHIzq());
       cout<<raiz->getPerson().getEntity();
       printInOrder(raiz->getHDer());
    }
} 
NodePerson* KDTree::insertar(vector<NodePerson> personas, int prof){
    if(!personas.empty()){
        int k = personas.size();
        int axis = prof % 2;

        //NUESTRO METODO SORT Y MEDIAN}
        if(axis == 0){ //esta en el eje x
            for(int i = 0; i< k;i++){
            for(int j=0;j<k-1;j++){
                if(personas[j].getPerson().getxCentro()>personas[j+1].getPerson().getxCentro()){
                    NodePerson aux = personas[j];
                    personas[j] = personas[j+1];
                    personas[j+1] =aux;
                }
            }    
        }
        }else{// axis = 1, eje y
            for(int i = 0; i< k;i++){
                for(int j=0;j<k-1;j++){
                    if(personas[j].getPerson().getyCentro()>personas[j+1].getPerson().getyCentro()){
                        NodePerson aux = personas[j];
                        personas[j] = personas[j+1];
                        personas[j+1] =aux;
                    }
                }    
            }
        }
        
        //busco la persona del medio para la raiz
        NodePerson mediana = personas[k/2];
        this->raiz = &mediana;
        vector<NodePerson>NodosIzq;
        vector<NodePerson> NodosDers;

        for(int i= 0; i<=k/2;i++){
            NodosIzq.push_back(personas[i]);
        }
        for(int i= (k/2)+1; i < k;i++){
            NodosDers.push_back(personas[i]);
        }
        this->raiz.getHIzq() = insertar(NodosIzq,prof+1);
    
    
    }    
}   