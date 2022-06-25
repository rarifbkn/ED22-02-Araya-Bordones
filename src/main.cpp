#include <iostream>
#include <stdlib.h>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui.hpp>
#include "logic/includes/Person.h"
#include "logic/includes/NodePerson.h"
#include "logic/includes/LinkedList.h"
#include <chrono>

using namespace std;
using namespace cv;

//def functions
void AdjustBox(Rect& box);
void calcularDistancia(LinkedList &list, vector<Person> NuevosCentroides,int numberPerson);

int main(int, char**) {
    //cronometro
    auto start = chrono::system_clock::now();
    auto end = chrono::system_clock::now();
    chrono::duration<float,milli> duration= end - start; 
    //cout<<duration.count() y mili es 1000 son 1 sec

    HOGDescriptor hog;
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

    string identidad ="ID";
    vector<Mat> imagenes ;
    LinkedList Personas;
    vector<Person> NuevosCentroides;
    Person p;
    int numberPerson = 0;
    int contEntrada = 0;
    int contSalidas = 0;
    //lectura de imagenes
    vector<string> paths;
    paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/secuencia de imagenes/imagen01.png");
    paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/secuencia de imagenes/imagen02.png");
    paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/secuencia de imagenes/imagen03.png");
    
    for(auto& path:paths){
        //limpiamos el vectoor
        NuevosCentroides.clear();
        //LECTURA IMAGEN
        Mat img = imread(path);

        if(!img.data){
        cout<< "Image not found";
        return -1;
        }
        //* FUNCION PARA CALCULAR DISTANCIA
        float distancia = 0;
        

        //*Mitad de la imagen
        int imgRow = img.rows+1;

        //*Linea de referencia
        line(img,Point(0,imgRow),Point(imgRow,img.cols+1),Scalar(255,255,0));

        vector<Rect> detections;
        hog.detectMultiScale(img,detections,0,Size(3,4),Size(4,4),1.05,2);   
        //itero por cada deteccion que reconoce el hog
        
        for(auto& detection :detections){
            //ajusta la caja
            AdjustBox(detection);

            //crea la identidad de la persona
            string aux = to_string(numberPerson);
            p = detection;
            p.setEntity(identidad + aux);
            //creo el nodo y lo inserto en la lista
            NodePerson nodo = NodePerson(p);
            Personas.insert(&nodo);

            putText(img,p.getEntity(),Point(p.getxCentro(),p.getyCentro()+5),FONT_HERSHEY_COMPLEX,0.60,Scalar(0,255,0));
            rectangle(img,Point(p.getxInitial(),p.getyInitial()),Point(p.getxFinal(),p.getyFinal()),Scalar(0,0,255),2);
            circle(img,Point(p.getxCentro(),p.getyCentro()),2,Scalar(0,255,0),2);
            //NuevosCentroides.push_back(p);
            numberPerson++; 
        }
        //calcularDistancia(Personas,NuevosCentroides,numberPerson);
        namedWindow("Image");
        imshow("Image",img);
        waitKey(0);
        destroyAllWindows();
    }

    Personas.~LinkedList();
}  

void AdjustBox(Rect& box){
     //Reajusta el rectangulo
        box.x += cvRound(box.width*0.1);
        box.width = cvRound(box.width*0.8);
        box.y += cvRound(box.height*0.06);
        box.height = cvRound(box.height*0.8);
}
    
void calcularDistancia(LinkedList &list, vector<Person> nuevosCentroides,int numberPerson){
    float distanciaC = 0;
    vector<float> distancias;
    for(int i=0; i<numberPerson;i++){
        distancias.clear();
        Person p1 = list.getPersonI(i); //* Tengo la persona
        for(auto& centroideP : nuevosCentroides){
            Person p2 = centroideP;
            int xCentro2 = p2.getxCentro();
            int yCentro2 = p2.getyCentro();
            distanciaC = sqrt(exp2(xCentro2-p1.getxCentro())+exp2(yCentro2-p1.getyCentro()));
            distancias.push_back(distanciaC);
        }
        for(auto& distancia:distancias){
            int Dmenor =9999999999999999;
            if(distancia < Dmenor){
                Dmenor = distancia;
            }
        }
        
    }    

}

