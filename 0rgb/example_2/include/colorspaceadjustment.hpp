
#ifndef ___COLORSPACEADJUSTMENT_H___ 
#define ___COLORSPACEADJUSTMENT_H___ 
#include <iostream>
#include <math.h>
//Eigen Library
#include <Eigen/Dense>
#include <Eigen/Geometry>
//OpenCV Library
#include <stdio.h>
#include <cstdlib>
// #include <opencv/cv.h>
// #include <opencv/highgui.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class ConvertTooRGB {

 public:
  ConvertTooRGB(void) = default;

     cv::Mat normalize(cv::Mat img);
    cv::Mat linearTransform(cv::Mat img); 
    Eigen::Matrix3d rotatePoint(double angle);
    cv::Mat fullRotation(cv::Mat img);
   // double getAngle();
    //cv::Mat applyRotation(cv::Mat img);


    private:
  //  double angleTheta;


};


// class inverseConvertToRGB {

//  public:
//   inverseConvertToRGB(void) = default;

#endif
