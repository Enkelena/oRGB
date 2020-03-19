#include "inversecolorpsaceadjustement.hpp"


Eigen::Matrix3d Inverse::rotatePoint(double angle) { 
     Eigen::Matrix3d _matrix;
            _matrix << 1, 0, 0, 
                       0, 1, 0,
                       0, 0, 1;


  _matrix(0,0) =  cos(angle * M_PI / 180);
  _matrix(0,1) = -sin(angle * M_PI / 180);
  _matrix(1,0) =  sin(angle * M_PI / 180);
  _matrix(1,1) =  cos(angle * M_PI / 180);

  return _matrix;
}

cv::Mat Inverse::fullRotation(cv::Mat img) {
   cv::MatIterator_<cv::Vec3d> itd, end;
   double thetaAngle=0;
   for( itd=img.begin<cv::Vec3d>(); itd!= img.end<cv::Vec3d>();++itd) {

      double b=(*itd)[0];
      double g=(*itd)[1];
      double r=(*itd)[2];
      double theta = atan2(r, g);
      double newTheta=0;
   
      if (theta< M_PI / 2) {
         newTheta = (2/3)*theta;
      }

      else if((theta>= (M_PI /3)) && (theta <=M_PI)) {
         newTheta = M_PI/3 + 4/3*(theta-M_PI/2);   
      } 
          thetaAngle=(newTheta-theta);
   
//   this->angleTheta = thetaAngle;
//  return thetaAngle;
 Eigen::Vector3d _local {(*itd)[0], (*itd)[1], (*itd)[2]};
 _local = rotatePoint(thetaAngle) * _local;
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