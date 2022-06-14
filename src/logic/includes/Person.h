#ifndef ES22 -02 -Araya -Bordones_PERSON_H
#define ES22 -02 -Araya -Bordones_PERSON_H
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

public:
    Person();
    Person(string entity, Mat img);

    Mat getImg();
    void setImg(Mat img);
    string getEntity();
    void setEntity(string entity);
    int getEntries();
    void setEntries(int contE);
    int getExit();
    void setExit(int contE);

    ~Person();



};

#endif