#include "colorspaceadjustment.hpp"

cv::Mat ConvertTooRGB::normalize(cv::Mat img) {
 img.convertTo(img, CV_64FC3);
    double r{0},b{0},g{0};
    cv::MatIterator_<cv::Vec3d> itd = img.begin<cv::Vec3d>(), itd_end = img.end<cv::Vec3d>();
    for(int i = 0; itd != itd_end; ++itd,++i)
    {    
      
    r = pow((static_cast<double>((*itd)(0)) / 255.0),(1/2.2));
    g = pow((static_cast<double>((*itd)(1)) / 255.0),(1/2.2));
    b = pow((static_cast<double>((*itd)(2)) / 255.0),(1/2.2));

    (*itd)[0] = r * 255.0;
    (*itd)[1] = g * 255.0;
    (*itd)[2] = b * 255.0;
    }
   
    return img;
} 

cv::Mat ConvertTooRGB::linearTransform(cv::Mat img) {
     Eigen::Matrix3d linear_matrix;
            linear_matrix << 0.2990, 0.5870, 0.1140, 
               0.5000, 0.5000, -1.0000,
               0.8660, -0.8660, 0.0000;
 double r{0},b{0},g{0};
   cv::MatIterator_<cv::Vec3d> itd, end;
   for( itd=img.begin<cv::Vec3d>(); itd!= img.end<cv::Vec3d>();++itd) {

     r= (*itd)[0];
     g= (*itd)[1];
     b= (*itd)[2];

      Eigen::Vector3d _local {r,g,b};

      _local = linear_matrix * _local;

      (*itd)[0]=(_local[0]);        
     (*itd)[1]=(_local[1]);
      (*itd)[2]=(_local[2]);
   }
   //  img.convertTo(img, CV_8UC3);

   return img;
}


Eigen::Matrix3d ConvertTooRGB::rotatePoint(double angle) { 
     Eigen::Matrix3d _matrix;
            _matrix << 1, 0, 0, 
                       0, 1, 0,
                       0, 0, 1;

//   _matrix(0,0) =  cos(angle * M_PI / 180);
//   _matrix(0,1) = -sin(angle * M_PI / 180);
//   _matrix(1,0) =  sin(angle * M_PI / 180);
//   _matrix(1,1) =  cos(angle * M_PI / 180);

  _matrix(1,1) =  cos(angle * M_PI / 180);
  _matrix(1,2) = -sin(angle * M_PI / 180);
  _matrix(2,1) =  sin(angle * M_PI / 180);
  _matrix(2,2) =  cos(angle * M_PI / 180);

  return _matrix;
}

cv::Mat ConvertTooRGB::fullRotation(cv::Mat img) {
   cv::MatIterator_<cv::Vec3d> itd, end;
   double thetaAngle=0;
   for( itd=img.begin<cv::Vec3d>(); itd!= img.end<cv::Vec3d>();++itd) {

      double b=(*itd)[0];
      double g=(*itd)[1];
      double r=(*itd)[2];
      double theta = atan2(r, g);
      double newTheta=0;
   
      if (theta< M_PI / 3) {
         newTheta = (3/2)*theta;
      }

      else if((theta>= (M_PI /3)) && (theta <=M_PI)) {
         newTheta = M_PI/2 + 3/4*(theta-M_PI/3);   
      } 

          thetaAngle=(newTheta-theta);
         // std::cout<<("kendi:", thetaAngle)<<std::endl;
 Eigen::Vector3d _local {(*itd)[0], (*itd)[1], (*itd)[2]};
 _local = rotatePoint(thetaAngle) * _local;
 }
         //  img.convertTo(img, CV_8UC3);

    return img;
}



// double ConvertTooRGB::getAngle()
// {
//   return this->angleTheta;
// }



// not needed anymore as it has all been implemented at another function above

// cv::Mat ConvertTooRGB::applyRotation(cv::Mat img) {

//    double angle11 = getAngle();
//    Eigen::Matrix3d _matrix = rotatePoint(angle11);

//    cv::MatIterator_<cv::Vec3d> itd, end;
//    for( itd=img.begin<cv::Vec3d>(); itd!= img.end<cv::Vec3d>();++itd) {

//       Eigen::Vector3d _local {(*itd)[0], (*itd)[1], (*itd)[2]};
      
      
//       _local = _matrix * _local;
//       } 
 
// return img; } 
