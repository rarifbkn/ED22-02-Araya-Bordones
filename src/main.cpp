#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "logic/includes/Person.h"
#include "logic/includes/Detector.h"
#include "logic/includes/NodePerson.h"
#include "logic/includes/LinkedList.h"

using namespace std;
using namespace cv;

//define functions

void menuGuardia();
void menuAdministrador();
void peopleDetect(Detector& detector, Mat img);
LinkedList Personas;
vector<Mat> imagenes;
Mat img;
VideoCapture video;
string ruta = "";
float puntoRef = 0;
int main(int, char**) {
    Detector detector;
    string response ;
    img = imread("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/imagen00");
    if(!img.data){
        cout << "image not found "<<endl;
        peopleDetect(detector,img);
    return -1;  
    }
}  
    /*
    int numberImg = 0;
    for(auto& imagen : imagenes){
        ruta = "C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/imagen0",numberImg;
        img = imread(ruta+".jpg"); 
        if(!img.data){
         cout << "image not found "<<endl;
        return -1;     
        }else{
            cout<< "uwu\n";
        }
        peopleDetect(detector,img);
        numberImg++;
    }
    **/
    
    
    /*
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
    */

void peopleDetect(Detector& detector, Mat frame){ 

    vector<Rect> detections;
    detector.getHog().detectMultiScale(img,detections,0,Size(3,4),Size(4,4),1.05,2);   
   
    // READJUST RECTANGLE TO IMAGE 
    int contador = 0;
    string entidad = "entidad0";
    for(auto& detection :detections){
        Person p = detection;
        entidad += contador;
        Personas.insert(entidad);
        
        detection.x +=cvRound(detection.width*0.1);
        detection.width =cvRound(detection.width*0.6);
        detection.y +=cvRound(detection.height*0.06);
        detection.height =cvRound(detection.height*0.8);

        //draw rectangle about person and the center circle
        rectangle(img,Point(p.getxInitials(),p.getyInitials()),Point(p.getxFinal(),p.getyFinal()),Scalar(0,0,255),2);
        circle(img,Point(p.getCentroX(),p.getCentroY()),2,Scalar(0,255,0),2);
        

    /**
    Mat matrix,imgWarp;
    Point2f src[4] = {};
    matrix = getPerspectiveTransform(detection.x,detection.y);
    warpPerspective(img,imgWarp,matrix,Point(detection.width,detection.height));
    */
    }
    cout << Personas.cantPersonas()<<endl;
    //detector.DetectP(img);
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


