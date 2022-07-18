#include <iostream>
#include <stdlib.h>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui.hpp>
#include "logic/includes/Person.h"
#include "logic/includes/NodePerson.h"
#include "logic/includes/LinkedList.h"
#include "logic/includes/Detector.h"
#include <chrono>

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
    vector<string> paths;
    int accion = 0;
    int numberPerson = 0;
    int zona = 0;
    int horas = duration.count()*3.6;
    //lectura de imagenes
    String respuesta = "";
    cout << "Como desea ingresar(guardia/administrador): ";
    cin >> respuesta;

    while(!respuesta._Equal("guardia") && !respuesta._Equal("administrador")){
        cout<<endl;
        cout << "error, ingrese una respuesta valida(guardia/administrador): ";
        cin >> respuesta;
    }
    cout<<endl;
    if(respuesta == "administrador"){  //de lo contrario entra al administrador
        accion = MenuAdmin();
        if(accion ==1){//path A
            paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/pathsA/imagen01.png");
            paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/pathsA/imagen02.png");
            paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/pathsA/imagen03.png");
        }else if(accion == 2){//path B
            paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/pathsB/imagen01.png");
            paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/pathsB/imagen02.png");
            paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/pathsB/imagen03.png");   
        }else{ // path C
            paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/pathsC/imagen01.png");
            paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/pathsC/imagen02.png");
            paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/pathsC/imagen03.png");
        } 
    }else{// si es el menu de guardia carga estas imagenes por defecto
            paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/pathsA/imagen01.png");
            paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/pathsA/imagen02.png");
            paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/pathsA/imagen03.png");    
    }  
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
        if(respuesta._Equal("guardia")){
                    DibujoPersonas(img,listaPersonas);
                    cout<< "La cantidad de personas entrando es de :"<< TraficoEntrada(listaPersonas, imgRow/2)<<endl;
                    cout<< "La cantidad de personas saliendo es de :"<< TraficoSalida(listaPersonas, imgRow/2)<<endl;
                    cout<< "La velocidad de personas/hora entrando es de: "<<TraficoEntrada(listaPersonas, imgRow/2)/horas<<endl;
                    cout<< "La velocidad de personas/hora saliendo es de: "<<TraficoSalida(listaPersonas, imgRow/2)/horas<<endl;
        }
    }

}  
int MenuAdmin(){
    int respuesta;
    cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"<<endl;
    cout<<";;;;;;;;  Bienvenido Administrador ;;;;;"<<endl;
    cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"<<endl;
    cout<<"seleccionar archivo de imagenes a analizar:";
    cout<<endl<<"1.pathA"<<endl;
    cout<<"2.pathB"<<endl;
    cout<<"3.pathC"<<endl;
    cin>>respuesta; 
    while (respuesta != 1 && respuesta != 2 && respuesta != 3 ){
        cout<<"ERROR...Por favor seleccione una opcion correcta:";
        cout<<"1.pathA"<<endl;
        cout<<"2.pathB"<<endl;
        cout<<"3.pathC"<<endl;
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
        imshow("Imagen",img);
        waitKey(0);
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


