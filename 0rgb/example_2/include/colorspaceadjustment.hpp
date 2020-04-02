
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
bool setNormalizeImage(cv::Mat img1);

/**
 * @brief function that returns a vector after it has been multiplied with a specific matrix given because of the formula
 * 
 * @param img 
 * @return cv::Mat 
 */
bool setLinearImage();

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
bool fullRotation();

/**
 * @brief It changes the values of ths second and third vector of the image
 * 
 * @param cb 
 * @param crg 
 * @param img 
 * @return cv::Mat 
 */


//cv::Mat filter(double cb, double crg, cv::Mat img);




/**
 * @brief Set the Filter values- it changes the value of the vectors Cyb and Crg
 * 
 * @param img 
 * @param cyb 
 * @param crg 
 * @return cv::Mat 
 */
cv::Mat setFilter(cv::Mat img,double cyb, double crg);


/**
 * @brief Returns the matrix value from the private variable 'normalizedImage', which has been previously set by SetNormalizedImage function. 
 * 
 * @return cv::Mat 
 */
cv::Mat getnormalizedImage();

/**
 * @brief Returns the matrix value from the private variable 'linearImage', which has been previously set by setLinearImage function. 
 * 
 * @return cv::Mat 
 */
cv::Mat getLinearImage();

/**
 * @brief Returns the matrix value from the private variable 'rotatedImage', which has been previously set by fullRotation() function.
 * 
 * @return cv::Mat 
 */
cv::Mat getRotatedImage();

enum  channel {L, Cyb, Crg};

/**
 * @brief Function to separate channels of the image
 * 
 * @param img 
 * @param c 
 * @return cv::Mat 
 */
cv::Mat channelExtraction( cv::Mat img1, channel c); 

private:
cv::Mat normalizedImage;
cv::Mat linearImage;
cv::Mat rotatedImage;
};

#endif
