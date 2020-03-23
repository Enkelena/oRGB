
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

/**
 * @brief Class that contains the functions to fully create the color space "oRGB"
 * 
 */
class ConvertTooRGB {
 public:
  ConvertTooRGB(void) = default;

/**
 * @brief Function that normalizes the values
 *  
 */
     cv::Mat normalize(cv::Mat img);

/**
 * @brief function that returns a vector after it has been multiplied with a specific matrix given because of the formula
 * 
 * @param img 
 * @return cv::Mat 
 */
    cv::Mat linearTransform(cv::Mat img);

/**
 * @brief contains a matrix of rotation, that we will use to rotate a vector in the next function
 * 
 * @param angle 
 * @return Eigen::Matrix3d 
 */
    Eigen::Matrix3d rotatePoint(double angle);


/**
 * @brief based on the angle taken from the vector of the loaded image, it rotates that vector using the previous rotatePoint function
 * 
 * @param img 
 * @return cv::Mat 
 */
    cv::Mat fullRotation(cv::Mat img);

   // double getAngle();
    //cv::Mat applyRotation(cv::Mat img);


};

#endif
