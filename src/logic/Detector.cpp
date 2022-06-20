#include "includes/Detector.h"

void Detector::DetectP(Mat img){    
    vector<Rect> detections;
    this->hog.detectMultiScale(img,detections,0,Size(4,4),Size(4,4),1,2);   
   
   for(auto& detection :detections){
    Person p = detection;
    detection.x +=cvRound(detection.width*0.1);
    detection.width =cvRound(detection.width*0.6);
    detection.y +=cvRound(detection.height*0.06);
    detection.height =cvRound(detection.height*0.8);

    rectangle(img,detection.tl(),detection.br(),Scalar(0,0,255),2);
    circle(img,Point(p.getCentroX(),p.getCentroY()),2,Scalar(0,255,0),2);
    }
}   

Detector::~Detector(){

}