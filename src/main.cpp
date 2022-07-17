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

int main(int, char**) {
    //cronometro
    auto start = chrono::system_clock::now();
    auto end = chrono::system_clock::now();
    chrono::duration<float,milli> duration= end - start; 
    //cout<<duration.count() y mili es 1000 son 1 sec

    Detector hog;
    LinkedList listaPersonas;
    int numberPerson = 0;
    int contEntrada = 0;
    int contSalidas = 0;
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
        
        //*mitad filas
        int imgRow = img.rows+1;
        //*Linea de referencia
        line(img,Point(0,imgRow),Point(imgRow,img.cols+1),Scalar(255,255,0));

        //*COMIENZO A RECORRER LA LISTA PARA LOS REQUERIMIENTOS 
        listaPersonas = hog.detect(img);
        
               
        //calcularDistancia(Personas,NuevosCentroides,numberPerson);
        namedWindow("Image");
        imshow("Image",img);
        waitKey(0);
        destroyAllWindows();
    }

}  


    


