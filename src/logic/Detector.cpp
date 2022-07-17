#include "includes/Detector.h"

Detector::Detector(){
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());    
}

//realiza la deteccion de las personas y las almacena en el arbol
KDTree Detector::detect(Mat img){
    KDTree arbol ;
    vector<Rect> detections;
    pointVec  puntos;
    vector <Person> personas;
    string id = "ID";
    int contP = 0;

    hog.detectMultiScale(img,detections,0,Size(3,4),Size(4,4),1.05,2);   
    for(auto& detection: detections){
        AdjustBox(detection);
        Person p = detection;
        contP++;
        p.setEntity(id + to_string(contP));

        personas.push_back(p); 
        puntos.push_back(p.getCord());

    }
    //reviso el arbol 
    if(arbol.getRaiz() == nullptr){//vacio
        arbol = KDTree(puntos);
    }
    return arbol; 
              
}

void Detector::AdjustBox(Rect& box){
    //Reajusta el rectangulo
        box.x += cvRound(box.width*0.1);
        box.width = cvRound(box.width*0.8);
        box.y += cvRound(box.height*0.06);
        box.height = cvRound(box.height*0.8);
}

