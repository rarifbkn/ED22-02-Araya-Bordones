#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <iomanip>

#include "KDTree.h"


using namespace cv;
using namespace std;


class Detector{
private:
    HOGDescriptor hog;
public:
    Detector();
    HOGDescriptor getDetector();
    KDTree detect(Mat img);
    void AdjustBox(Rect& box);
    };