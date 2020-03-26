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
   cv::Mat img1 = img.clone();
   double thetaAngle=0;
   double r{0},b{0},g{0};
   cv::MatIterator_<cv::Vec3d> itd, end;
   for( itd=img1.begin<cv::Vec3d>(); itd!= img1.end<cv::Vec3d>();++itd) {

       r=(*itd)[0];
       g=(*itd)[1];
       b=(*itd)[2];

      double theta = atan2(b, g);
      double newTheta=0;
   
      if (theta< M_PI / 2) {
         newTheta = (2/3)*theta;
      }

       if((theta>= (M_PI /3)) && (theta <=(5*M_PI/3)))  {
         newTheta = M_PI/3 + 4/3*(theta-M_PI/2);   
      } 

      if((theta> 5*M_PI / 3) && (theta <(2*M_PI)) ) {
         newTheta = (2/3)*theta;
      }
   
      thetaAngle=(newTheta-theta);
   
      Eigen::Vector3d _local {r,g,b};
      _local = rotatePoint(thetaAngle) * _local;
  
      (*itd)[0]=(_local[0]);        
      (*itd)[1]=(_local[1]);
      (*itd)[2]=(_local[2]);
 }
    return img1;
}


cv::Mat Inverse::linearTransform(cv::Mat img) {
       cv::Mat img1 = img.clone();
      Eigen::Matrix3d linear_matrix;

      linear_matrix << 1.0000, 0.1140, 0.7436,
      1.0000, 0.1140, -0.4111,
      1.0000, -0.8860,0.1663;

      double gamma = 2.2f;

      cv::MatIterator_<cv::Vec3d> itd, end;
      for( itd=img1.begin<cv::Vec3d>(); itd!= img1.end<cv::Vec3d>();++itd) 
      {
         Eigen::Vector3d _local {(*itd)[0], (*itd)[1], (*itd)[2]};

         _local = linear_matrix * _local;

         (*itd)[0]=(_local(0))*255;
         (*itd)[1]=(_local(1))*255;
         (*itd)[2]=(_local(2))*255;

         (*itd)[0] = pow((static_cast <double>((*itd)[0]) / 255.0 ),gamma)*255;
         (*itd)[1] = pow((static_cast <double>((*itd)[1]) / 255.0 ),gamma)*255;
         (*itd)[2] = pow((static_cast <double>((*itd)[2]) / 255.0 ),gamma)*255; 
       }
    img1.convertTo(img1, CV_8UC3);
   return img1;
}  

