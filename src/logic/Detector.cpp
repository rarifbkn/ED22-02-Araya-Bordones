#include "includes/Detector.h"

Detector::Detector(){
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
}

LinkedList Detector::detect(Mat img){

        vector<Rect> detections;
        LinkedList listaPersonas;

        int numberPerson = 0;
        string id = "ID";
        hog.detectMultiScale(img,detections,0,Size(3,4),Size(4,4),1.05,2);
        for(auto& detection :detections){
            cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"<<endl;
            cout<<";;;;;;;;      DETECTANDO    ;;;;;;;"<<endl;
            cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"<<endl;
            //ajusta la caja
            AdjustBox(detection);
            Person p;
            //crea la identidad de la persona
            p = detection;
            p.setEntity(id + to_string(numberPerson));
            //creo el nodo y lo inserto en la lista
            listaPersonas.insert(p);
            numberPerson++; 
        }
        cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"<<endl;
        cout<<";;;;;;;;      retorno    ;;;;;;;"<<endl;
        cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"<<endl;
        return listaPersonas;
}
void Detector::AdjustBox(Rect& box){
     //Reajusta el rectangulo
        box.x += cvRound(box.width*0.1);
        box.width = cvRound(box.width*0.8);
        box.y += cvRound(box.height*0.06);
        box.height = cvRound(box.height*0.8);
}