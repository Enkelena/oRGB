#ifndef ___INVERSECOLORPSACEADJUSTEMENT_H___ 
#define ___INVERSECOLORPSACEADJUSTEMENT_H___ 
#include <iostream>
#include <math.h>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <stdio.h>
#include <cstdlib>
// #include <opencv/cv.h>
// #include <opencv/highgui.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Inverse {

 public:
  Inverse(void) = default;

   // cv::Mat normalize(cv::Mat img);
    cv::Mat linearTransform(cv::Mat img); 
    Eigen::Matrix3d rotatePoint(double angle);
    cv::Mat fullRotation(cv::Mat img);

};


#endif
