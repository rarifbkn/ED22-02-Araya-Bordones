#ifndef DETECTOR_H
#define DETECTOR_H
#include "Person.h"

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class Detector{
private:
    HOGDescriptor hog;

public:
    Detector(): hog() {
        hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

    }

    void DetectP(Mat img);
    ~Detector();
};


#endif