#ifndef ___OPENCV_WRAPPER_H___ 
#define ___OPENCV_WRAPPER_H___ 

#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <iostream>
#include <unsupported/Eigen/MatrixFunctions>

class ConvertTooRGB {


 public:
  ConvertTooRGB(void) = default;

    Eigen::Vector3d nonlinearity( Eigen::Vector3d rgb);

    Eigen::Vector3d linearTransform( Eigen::Vector3d point);

};
#endif

