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
Person* KDTree::insertar(vector<Person> personas, int prof){
    if(!personas.empty()){
        int k = personas.size();
        int axis = prof % k; // creo q es %k

        //NUESTRO METODO SORT Y MEDIAN}
        if(axis == 0){ //esta en el eje x
            for(int i = 0; i< k;i++){
                for(int j=0;j<k;j++){
                    if(personas[j].getxCentro()>personas[j+1].getxCentro()){
                        Person aux = personas[j];
                        personas[j] = personas[j+1];
                        personas[j+1] =aux;
                    }
                }    
            }
        }
        else{// axis = 1, eje y
            for(int i = 0; i< k;i++){
                for(int j=0;j<k;j++){
                    if(personas[j].getyCentro()>personas[j+1].getyCentro()){
                        Person aux = personas[j];
                        personas[j] = personas[j+1];
                        personas[j+1] =aux;
                    }
                }    
            }
        }
        
        //busco la persona del medio para la raiz
        Person *Pmediana = &personas[k/2];
        vector<Person> personasIzq;
        vector<Person> personasDer;

        for(int i= 0; i<=k/2;i++){
            personasIzq.push_back(personas[i]);
        }
        for(int i= (k/2)+1; i < k;i++){
            personasDer.push_back(personas[i]);
        }
        Pmediana = insertar(personasIzq,prof+1);
        Pmediana = insertar(personasDer,prof+1);
        return Pmediana;
    } 
    return nullptr;   
}   