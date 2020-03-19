
#ifndef ___OPENCV_WRAPPER_H___ 
#define ___OPENCV_WRAPPER_H___ 
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

 
   // Eigen::Vector3d nonlinearity( Eigen::Vector3d rgb);

   // Eigen::Vector3d linearTransform( Eigen::Vector3d point);

    cv::Mat normalize(cv::Mat img);
    cv::Mat linearTransform(cv::Mat img); 
    double getNewangle(cv::Mat img);
    double getAngle();
    Eigen::Matrix3d rotatePoint(double angle);
    cv::Mat applyRotation(cv::Mat img);


    private:
    double angleTheta;


};
#endif
