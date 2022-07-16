#ifndef TALLER_PERSON_H
#define TALLER_PERSON_H
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;
using point_t = std::vector< double>;

class Person{
private:
    Mat img;
    string entity;
    Rect rectangulo;
    int area;
    int xInitial;
    int yInitial;
    int xFinal;
    int yFinal;
    int xCentro;
    int yCentro;
    point_t centroCordenadas;

public:
    Person();
    Person(Rect& r);
    vector<double> getCord();
    Mat getImg();
    string getEntity();
    int getEntries();
    int getExit();
    int getxInitial();
    int getyInitial();
    int getyFinal();
    int getxFinal();
    int getxCentro();
    int getyCentro();
    Rect getRectangulo();
 
    void setImg(Mat newImg);
    void setEntity(string newEntity);
    void setxInitial(int x);
    void setyInitial(int y);
    void setxFinal(int x);
    void setyFinal(int y);
    void setxCentro(int x);
    void setyCentro(int y);
    void setRectangulo(Rect r);
    
};

#endif