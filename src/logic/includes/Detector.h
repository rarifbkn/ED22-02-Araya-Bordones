#ifndef DETECTOR_H
#define DETECTOR_H
#include "Person.h"

#include <opencv2/opencv.hpp>
#include "Person.h"

using namespace cv;
using namespace std;

class Detector{
private:
    HOGDescriptor hog;
    bool estado = false;
    //true entrar and false salir
    

public:
    Detector(): hog() {
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

    }
    HOGDescriptor getHog();
    bool getEstado();
    ~Detector();
};


#endif