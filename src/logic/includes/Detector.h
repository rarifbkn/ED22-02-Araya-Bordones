#include "LinkedList.h"
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <iomanip>  

class Detector{
    private:
        HOGDescriptor hog;
    public:
        Detector(): hog(){
            hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector()); 
        }
        LinkedList detect(Mat img);
        void AdjustBox(Rect& box);

};