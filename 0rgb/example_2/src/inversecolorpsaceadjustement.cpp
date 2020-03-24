#include "inversecolorpsaceadjustement.hpp"


Eigen::Matrix3d Inverse::rotatePoint(double angle) { 
     Eigen::Matrix3d _matrix;
            _matrix << 1, 0, 0, 
                       0, 1, 0,
                       0, 0, 1;

  _matrix(1,1) =  cos(angle * M_PI / 180);
  _matrix(1,2) = -sin(angle * M_PI / 180);
  _matrix(2,1) =  sin(angle * M_PI / 180);
  _matrix(2,2) =  cos(angle * M_PI / 180);

  return _matrix;
}

cv::Mat Inverse::fullRotation(cv::Mat img) {
  double thetaAngle=0;
    double r{0},b{0},g{0};
   cv::MatIterator_<cv::Vec3d> itd, end;
   for( itd=img.begin<cv::Vec3d>(); itd!= img.end<cv::Vec3d>();++itd) {

       r=(*itd)[0];
       g=(*itd)[1];
       b=(*itd)[2];
      double theta = atan2(b, g);
      double newTheta=0;
   
      if (theta< M_PI / 2) {
         newTheta = (2/3)*theta;
      }

      if((theta>= (M_PI /3)) && (theta <=M_PI)) {
         newTheta = M_PI/3 + 4/3*(theta-M_PI/2);   
      } 
   
      thetaAngle=(newTheta-theta);
   
      Eigen::Vector3d _local {r,g,b};
      _local = rotatePoint(thetaAngle) * _local;

  
      (*itd)[0]=(_local[0]);        
     (*itd)[1]=(_local[1]);
      (*itd)[2]=(_local[2]);
 }
    return img;
}


cv::Mat Inverse::linearTransform(cv::Mat img) {

     Eigen::Matrix3d linear_matrix;

      linear_matrix << 1.0000, 0.1140, 0.7436,
      1.0000, 0.1140, -0.4111,
      1.0000, -0.8860,0.1663;

      cv::MatIterator_<cv::Vec3d> itd, end;
      for( itd=img.begin<cv::Vec3d>(); itd!= img.end<cv::Vec3d>();++itd) {

      Eigen::Vector3d _local {(*itd)[0], (*itd)[1], (*itd)[2]};

      _local = linear_matrix * _local;

      (*itd)[0]=(_local(0));
      (*itd)[1]=(_local(1));
      (*itd)[2]=(_local(2));
   }

   return img;
}  


cv::Mat Inverse::normalizeBack(cv::Mat img) {
    double r{0},b{0},g{0};
    cv::MatIterator_<cv::Vec3d> itd = img.begin<cv::Vec3d>(), itd_end = img.end<cv::Vec3d>();
    for(int i = 0; itd != itd_end; ++itd,++i)
    {    
      
    r = pow((static_cast<double>((*itd)(0)) / 255.0),(2.2));
    g = pow((static_cast<double>((*itd)(1)) / 255.0),(2.2));
    b = pow((static_cast<double>((*itd)(2)) / 255.0),(2.2));

    (*itd)[0] = r * 255.0;
    (*itd)[1] = g * 255.0;
    (*itd)[2] = b * 255.0;
    }
       img.convertTo(img, CV_8UC3);

    return img;
    
} 