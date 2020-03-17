#include "colorspaceadjustment.hpp"

  
    Eigen::Vector3d ConvertTooRGB::nonlinearity( Eigen::Vector3d rgb) {
     
     Eigen::Vector3d result;
     result=rgb;

      result[0]=pow(result[0],0.4545455)*255;
      result[1]=pow(result[1],0.4545455)*255;
      result[2]=pow(result[2],0.4545455)*255;

      return result;
    }


    Eigen::Vector3d ConvertTooRGB::linearTransform( Eigen::Vector3d point) { 
       
       Eigen::Matrix3d linear_matrix;
            linear_matrix << 0.2990, 0.5870, 0.1140,
               0.5000, 0.5000, -1.0000,
               0.8660, -0.8660, 0.0000;
       
       Eigen::Vector3d result;
       result =  linear_matrix * point;

       return result;
    }

//------------------------------------






