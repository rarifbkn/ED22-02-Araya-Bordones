#include <iostream>
#include <opencv2/opencv.hpp>
#include "logic/includes/Person.h"
#include "logic/includes/Detector.h"
#include "logic/includes/NodePerson.h"
#include "logic/includes/LinkedList.h"

using namespace std;
using namespace cv;

//define functions

void menuGuardia();
void menuAdministrador();
void ResizeBoxes(Rect &box);
void peopleDetect(Detector& detector, Mat img);


Mat img;

int main(int, char**) {
    Detector detector;
    string response ;
    img = imread("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/Prueba2.jpg");
    
    if(!img.data){
        cout << "image not found "<<endl;
        return -1;     
    }

    peopleDetect(detector,img);
    
    cout <<"Ingrese su usuario (guardia/administrador): "<<endl;
    cin>>response;
    //compruebo que fue guardia/administrador
    while(!response._Equal("guardia") && !response._Equal("administrador")){
        cout <<"Ingrese un usuario valido por favor (guardia/administrador): "<<endl;
        cin>>response;    
    }
   
    if(response._Equal("guardia")){
        menuGuardia();
    }else{
        menuAdministrador();
    }

}

void peopleDetect(Detector& detector, Mat img){ 

    detector.DetectP(img);
    namedWindow("Picture");
    imshow("Picture", img);
    waitKey(0);
}

void menuGuardia(){
    cout<<"Bienvenido al menu Guardia D:\n";
}
void menuAdministrador(){
    cout<<"Bienvenido al menu administrador :D\n";
}


