#include <iostream>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "logic/includes/Person.h"
#include "logic/includes/NodePerson.h"
#include <chrono>

using namespace std;
using namespace cv;

//def functions
void AdjustBox(Rect& box);
float calcularDistancia(Person p1, Person p2);

int main(int, char**) {
    //cronometro
    auto start = chrono::system_clock::now();
    auto end = chrono::system_clock::now();
    chrono::duration<float,milli> duration= end - start; 
    //cout<<duration.count() y mili es 1000 son 1 sec

    //*histograma de gradientes
    HOGDescriptor hog;
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

    string identidad ="ID";
    vector<Mat> imagenes ;
    list<Person> nuevasPersonas;
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
        nuevasPersonas.clear();
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
            p = detection;
            

        }

        //esto es nuevo
        for(int i=0; i<numberPerson;i++){
            Person p1 = Personas.getPersonI(i);
            distancias.clear();
            for(auto &personaNueva : nuevasPersonas){
                Person p2 = personaNueva;
                float distancia = calcularDistancia(p1,p2);
                distancias.push_back(distancia);
            }
            distancias.sort();
            float distMenor = distancias.front();
            for(auto &personaNueva : nuevasPersonas){
                Person p2 = personaNueva;
                float distancia = calcularDistancia(p1,p2);
                if(distancia == distMenor){
                    p1.setRectangulo(p2.getRectangulo());
                    nuevasPersonas.remove(p2);
                }
            }
        }
        //inserto a los centroides solitarios
        for(auto &personaNueva : nuevasPersonas){
                Person p2 = personaNueva;
                NodePerson nodito = NodePerson(p2);
                Personas.insert(&nodito);
        }
        for(auto& detection :detections){
        //ajusta la caja
        AdjustBox(detection);
        //crea la identidad de la persona
        string aux = to_string(numberPerson);
        p = detection;
        p.setEntity(identidad + aux);
        putText(img,p.getEntity(),Point(p.getxCentro(),p.getyCentro()+5),FONT_HERSHEY_COMPLEX,0.60,Scalar(0,255,0));
        rectangle(img,Point(p.getxInitial(),p.getyInitial()),Point(p.getxFinal(),p.getyFinal()),Scalar(0,0,255),2);
        circle(img,Point(p.getxCentro(),p.getyCentro()),2,Scalar(0,255,0),2);
        numberPerson++; 
        }
        //calcularDistancia(Personas,NuevosCentroides,numberPerson);
        namedWindow("Image");
        imshow("Image",img);
        waitKey(0);
        destroyAllWindows();
    }
}  

void AdjustBox(Rect& box){
     //Reajusta el rectangulo
        box.x += cvRound(box.width*0.1);
        box.width = cvRound(box.width*0.8);
        box.y += cvRound(box.height*0.06);
        box.height = cvRound(box.height*0.8);
}
    
float calcularDistancia(Person p1, Person p2){
    float distancia = 0;
    return distancia;
}


