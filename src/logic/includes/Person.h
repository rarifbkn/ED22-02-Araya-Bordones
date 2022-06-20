#ifndef TALLER_PERSON_H
#define TALLER_PERSON_H
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

class Person{
private:
    Mat img;
    string entity;
    int contEntries; 
    int contExit;
    int xInitials;
    int yInitials;
    int centroX;
    int centroY;
    int xFinal;
    int yFinal;


public:
    Person(Rect& r);

    Mat getImg();
    string getEntity();
    int getEntries();
    int getExit();
    int getxInitials();
    int getyInitials();
    int getCentroX();
    int getCentroY();
    int getyFinal();
    int getxFinal();
      
    void setImg(Mat img);
    void setEntity(string entity);
    void setEntries(int contE);
    void setExit(int contE);
    void setxInitials(int x);
    void setyInitials(int y);
    void setCentroX(int x);
    void setCentroY(int y);
    void setxFinal(int x);
    void setyFinal(int y);
    ~Person();



};

#endif