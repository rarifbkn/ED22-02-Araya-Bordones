#include "includes/Detector.h"

void Detector::DetectP(Mat img){    

    //DETECT PEOPLE
    vector<Rect> detections;
    this->hog.detectMultiScale(img,detections,0,Size(3,4),Size(4,4),1.05,2);   
   
    // READJUST RECTANGLE TO IMAGE 
    for(auto& detection :detections){
    Person p = detection;
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
    
}   

Detector::~Detector(){

}