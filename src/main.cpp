#include <iostream>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "logic/includes/Person.h"
#include "logic/includes/NodePerson.h"
#include "logic/includes/KDTree.h"
#include <chrono>

//!SI SE LIMPIA LA LISTA DE NODITOS COMO ELIMINAMOS A LA PERSONA CUANDO SALE DEL FRAME
//!COMO INSERTAMOS A LA NUEVA PERSONA EN EL FRAME

using namespace std;
using namespace cv;

//def functions
void AdjustBox(Rect& box);
int MenuGuardia();
int MenuAdmin();

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
    KDTree arbol ;
    vector<Person> personas;
    Person p;

    int accion = 0;
    int numberPerson = 0;
    int contEntrada = 0;
    int contSalidas = 0;
    int area = 0;

    //lectura de imagenes
    vector<string> paths;
    paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/secuencia de imagenes/imagen01.png");
    paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/secuencia de imagenes/imagen02.png");
    paths.push_back("C:/Users/Usuario/Documents/GitHub/ES22-02-Araya-Bordones/src/secuencia de imagenes/imagen03.png");
    for(auto& path:paths){
        //*MENUS 
        String respuesta = "";
        cout << "Como desea ingresar(guardia/administrador): ";
        cin >> respuesta;
       
        while(respuesta != "guardia"||respuesta != "administrador"){
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

        //lee la imagem
        Mat img = imread(path);

        //Comprueba si la imagen  esta
        if(!img.data){
        cout<< "Image not found";
        return -1;
        }
        //*Mitad de la imagen
        int imgRow = img.rows+1;
        //*Linea de referencia
        line(img,Point(0,imgRow),Point(imgRow,img.cols+1),Scalar(255,255,0));

        vector<Rect> detections;
        hog.detectMultiScale(img,detections,0,Size(3,4),Size(4,4),1.05,2);   
        //itero por cada deteccion que reconoce el hog
        
        //!aca debiese solo iterar el arbol de personas detectadas

        for(auto& detection :detections){
            
            //ajusta la caja
            AdjustBox(detection);
            //crea la identidad de la persona
            string aux = to_string(numberPerson);
            p = detection;

            //! revisar como comparar areas para saber si entran o salen, crear etiquetas >:vvvvv
            if(p.getxCentro() > imgRow && p.getyCentro() > img.cols+1 ){ // lo compara con la linea del centro

            }
            p.setEntity(identidad + aux);

            /*
            identificaremos las areas 1 y 2 para saber si entran o salen segun cambien de un area a otra
            */

            // llamo al arbol e invoco el requerimiento


            putText(img,p.getEntity(),Point(p.getxCentro(),p.getyCentro()+5),FONT_HERSHEY_COMPLEX,0.60,Scalar(0,255,0));
            rectangle(img,Point(p.getxInitial(),p.getyInitial()),Point(p.getxFinal(),p.getyFinal()),Scalar(0,0,255),2);
            circle(img,Point(p.getxCentro(),p.getyCentro()),2,Scalar(0,255,0),2); 
            personas.push_back(p);
            //nos sirve para el ID y el numero de este: ej: "ID2"
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
    return respuesta;     
}

int MenuAdmin(){
    int respuesta;
    cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"<<endl;
    cout<<";;;;;;;;  Bienvenido Administrador ;;;;;"<<endl;
    cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"<<endl;
    cout<<"seleccione la accion a realizar con la secuencia actual"<<endl;
    cout<<"1. seleccionar archivo de imagenes a analizar"<<endl;
    cin>>respuesta;     
    return respuesta;    
}


