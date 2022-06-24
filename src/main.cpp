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
void Reajust(Rect& box);
 void calcularDistancia(LinkedList &list, int number);

Mat img;

int main(int, char**) {
    //cronometro
    auto start = chrono::system_clock::now();
    auto end = chrono::system_clock::now();
    chrono::duration<float,milli> duration= end - start; 
    //cout<<duration.count() y mili es 1000 son 1 sec

    HOGDescriptor hog;
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

   
    string identidad ="ID";
    LinkedList Personas;
    Person p;
    int number = 0;
    int contEntrada = 0;
    int contSalidas = 0;

    img = imread("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/secuencia de imagenes/Prueba2.jpg");//lee la imagen
    if(!img.data){
        cout << "image not found "<<endl;
    return -1;  
    }

    int altoImg = img.cols+1; //mitad de la imagen

    vector<Rect> detections;
    hog.detectMultiScale(img,detections,0,Size(3,4),Size(4,4),1.05,2);   
    //itero por cada deteccion que reconoce el hog
    for(auto& detection :detections){
        string aux = to_string(number);
        p = detection;
        p.setEntity(identidad+aux);
       
        //draw rectangle about person and the center circle
        rectangle(img,Point(p.getxInitial(),p.getyInitial()),Point(p.getxFinal(),p.getyFinal()),Scalar(0,0,255),2);
        circle(img,Point(p.getxCentro(),p.getyCentro()),2,Scalar(0,255,0),2);

        //creo el nodo y lo inserto en la lista
        NodePerson nodito = NodePerson(p);
        Personas.insert(&nodito);

        //draw reference line
        line(img,Point(altoImg/2,0),Point(altoImg/2,img.cols),Scalar(0,255,255),2);
        
        number++; 
    }
    //x cada persona calcule la distancia euclidiana respecto de los otros centroides para asi saber si se movio o es otra persona 
    //calcularDistancia(Personas,number);
    namedWindow("Imagen");
    imshow("Imagen", img);
    waitKey(0);
    destroyAllWindows();
}  

void Reajust(Rect& box){
     //Reajusta el rectangulo
        box.x += cvRound(box.width*0.1);
        box.width = cvRound(box.width*0.8);
        box.y += cvRound(box.height*0.06);
        box.height = cvRound(box.height*0.8);
}
void calcularDistancia(LinkedList &list,int number){
    //asumo que la lista no es 0
    double distancia =0.0;
    NodePerson *aux = list.getFirst();
    

}

