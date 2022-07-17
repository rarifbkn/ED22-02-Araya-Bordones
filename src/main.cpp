#include <iostream>
#include <stdlib.h>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui.hpp>
#include "logic/includes/Person.h"
#include "logic/includes/NodePerson.h"
#include "logic/includes/LinkedList.h"
#include "logic/includes/Detector.h"
#include <chrono>

using namespace std;
using namespace cv;

//def functions
void AdjustBox(Rect& box);
int MenuGuardia();
int MenuAdmin();
void DibujoPersonas(Mat img,LinkedList listaPersonas);
int TraficoEntrada(LinkedList listaPersonas,float mitadFila);
int TraficoSalida(LinkedList listaPersonas, float mitadFila);



int main(int, char**) {
    //cronometro
    auto start = chrono::system_clock::now();
    auto end = chrono::system_clock::now();
    chrono::duration<float,milli> duration= end - start; 
    //cout<<duration.count() y mili es 1000 son 1 sec

    Detector hog ;
    LinkedList listaPersonas;
    int accion = 0;
    int numberPerson = 0;
    int zona = 0;

    //lectura de imagenes
    vector<string> paths;
    paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/secuencia de imagenes/imagen01.png");
    paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/secuencia de imagenes/imagen02.png");
    paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/secuencia de imagenes/imagen03.png");
    for(auto& path:paths){
        //LECTURA IMAGEN
        Mat img = imread(path);
        if(!img.data){
        cout<< "Image not found";
        return -1;
        }
        listaPersonas = hog.detect(img);
        //mitad filas
        int imgRow = img.rows+1;
        //linea de referencia
        line(img,Point(0,imgRow),Point(imgRow,img.cols+1),Scalar(255,255,0));
        //
        String respuesta = "";
        cout << "Como desea ingresar(guardia/administrador): ";
        cin >> respuesta;

        while(!respuesta._Equal("guardia") && !respuesta._Equal("administrador")){
            cout<<endl;
            cout << "error, ingrese una respuesta valida(guardia/administrador): ";
            cin >> respuesta;
        }
        cout<<endl;
        if(respuesta == "guardia"){
            accion = MenuGuardia();
        }else { //de lo contrario entra al administrador
            accion = MenuAdmin();
        }
        
        if(respuesta._Equal("guardia")){
            switch(accion){
                case 1:
                    DibujoPersonas(img,listaPersonas);
                    break;
                case 2:
                    cout<< "La cantidad de personas entrando es de :"<< TraficoEntrada(listaPersonas, imgRow/2)<<endl;
                    break;
                case 3:
                    cout<< "La cantidad de personas entrando es de :"<< TraficoSalida(listaPersonas, imgRow/2)<<endl;
                    break;
                case 4:
                    
                    break;
                case 5:
                    
                    break;
            }
        }
        
               
       
    }

}  

int MenuGuardia(){
    int respuesta;
    cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"<<endl;
    cout<<";;;;;;;;  BIENVENIDO GUARDIA :D  ;;;;;;;"<<endl;
    cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"<<endl;
    cout<<"seleccione la accion a realizar con la secuencia actual"<<endl;
    cout<<"1. Dibujo de las personas en la imagen"<<endl;
    cout<<"2. Trafico de entrada"<<endl;
    cout<<"3. Trafico de salida"<<endl;
    cout<<"4. Velocidad de entrada personas/hora "<<endl;
    cout<<"5. Velocidad de salida personas/hora "<<endl;
    cin>>respuesta;
    while(respuesta != 1 && respuesta != 2 && respuesta != 3 && respuesta != 4 && respuesta != 5){
        cout<<"ERROR...Por favor seleccione una opcion correcta:";
        cout<<endl<<"1. Dibujo de las personas en la imagen"<<endl;
        cout<<"2. Trafico de entrada"<<endl;
        cout<<"3. Trafico de salida"<<endl;
        cout<<"4. Velocidad de entrada personas/hora "<<endl;
        cout<<"5. Velocidad de salida personas/hora "<<endl;
        cin>>respuesta;
    }
    return respuesta;     
}
int MenuAdmin(){
    int respuesta;
    cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"<<endl;
    cout<<";;;;;;;;  Bienvenido Administrador ;;;;;"<<endl;
    cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"<<endl;
    cout<<"seleccione la accion a realizar con la secuencia actual:";
    cout<<endl<<"1. seleccionar archivo de imagenes a analizar"<<endl;
    cin>>respuesta; 
    while (respuesta != 1){
        cout<<"ERROR...Por favor seleccione una opcion correcta:";
        cout<<endl<<"1. seleccionar archivo de imagenes a analizar"<<endl;
        cin>>respuesta;     
    }    
    return respuesta;    
}

void DibujoPersonas(Mat img, LinkedList listaPersonas){
    Person *persona = &listaPersonas.getFirst()->getPerson();
    while(persona != nullptr){
        persona = &listaPersonas.getFirst()->getPerson(); 
        Person p = *persona;
        putText(img,p.getEntity(),Point(p.getxCentro(),p.getyCentro()+5),FONT_HERSHEY_COMPLEX,0.60,Scalar(0,255,0));
        rectangle(img,Point(p.getxInitial(),p.getyInitial()),Point(p.getxFinal(),p.getyFinal()),Scalar(0,0,255),2);
        circle(img,Point(p.getxCentro(),p.getyCentro()),2,Scalar(0,255,0),2);
        }
    }
    

int TraficoEntrada(LinkedList listaPersonas, float mitadFila){
    int cont = 0;
    Person *persona = &listaPersonas.getFirst()->getPerson();
    while(persona != nullptr){
        persona = &listaPersonas.getFirst()->getPerson(); 
        Person p = *persona;
        if(p.getxCentro() > mitadFila ){
            cont++;
        }       
    }
    return cont;
}    

int TraficoSalida(LinkedList listaPersonas, float mitadFila){
     int cont = 0;
    Person *persona = &listaPersonas.getFirst()->getPerson();
    while(persona != nullptr){
        persona = &listaPersonas.getFirst()->getPerson(); 
        Person p = *persona;
        if(p.getxCentro() < mitadFila ){
            cont++;
        }       
    }
    return cont;
}


