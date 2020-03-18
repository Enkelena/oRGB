#include "colorspaceadjustment.hpp"

   // (itd)[0] =(pow((float)((itd)[0]/ 255.0),1/gama));
   // (itd)[1] =(pow((float)((itd)[1]/ 255.0),1/gama));  
   // (itd)[2] =(pow((float)((itd)[2]/ 255.0),1/gama));  

// (*itd)[0] = (pow((float)((itd)[0] / 255.0), (1 / gamma))*255.0f);
// (*itd)[1] = (pow((float)((itd)[1] / 255.0), (1 / gamma))*255.0f);
// (*itd)[2] = (pow((float)((itd)[2] / 255.0), (1 / gamma))*255.0f);


cv::Mat ConvertTooRGB::normalize(cv::Mat img) {
   cv::MatIterator_<cv::Vec3d> itd, end;
   for( itd=img.begin<cv::Vec3d>(); itd!= img.end<cv::Vec3d>();++itd) {

         double gamma =2.2;
         // (itd)[0] = (pow(((itd)[0] / 255.0), 1 / gama)*255.0);
         // (itd)[1] = (pow(((itd)[1] / 255.0), 1 / gama)*255.0);
         // (itd)[2] = (pow(((itd)[2] / 255.0), 1 / gama)*255.0);

         (*itd)[0] = (pow((double)((*itd)[0] / 255.0), 1.0 / gamma)*255.0);
         (*itd)[1] = (pow((double)((*itd)[2] / 255.0), 1.0 / gamma)*255.0);
         (*itd)[2] = (pow((double)((*itd)[2] / 255.0), 1.0 / gamma)*255.0);

   }
   return img;
}



cv::Mat ConvertTooRGB::linearTransform(cv::Mat img) {

     Eigen::Matrix3d linear_matrix;
            linear_matrix << 0.2990, 0.5870, 0.1140, 
               0.5000, 0.5000, -1.0000,
               0.8660, -0.8660, 0.0000;

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

cv::Mat ConvertTooRGB::getNewangle(cv::Mat img) {
   cv::MatIterator_<cv::Vec3d> itd, end;
   for( itd=img.begin<cv::Vec3d>(); itd!= img.end<cv::Vec3d>();++itd) {

      double theta = atan2(itd[2], itd[1]); // help here is it should be these indexes or tan2(itd[1], itd[2]); because of BGR - RGB confusion
      double newTheta;

      if (theta< M_PI / 3) {
         newTheta = (3/2)*theta;
      }

      else if((theta>= (M_PI /3)) && (theta <=M_PI)) {
         newTheta = M_PI/2 + 3/4*(theta-M_PI/3);   
      }

      this->angleTheta=(newTheta-theta);
      return (newTheta-theta);
} }

Eigen::Matrix3d ConvertTooRGB::getAngle()
{
  return this->angle;
}


cv::Mat ConvertTooRGB::rotatePoint(double angle)
{

     Eigen::Matrix3d _matrix;
            _matrix << 1, 0, 0, 
                       0, 1, 0,
                       0, 0, 1;

     angle = getAngle();

  _matrix(0,0) =  cos(angle * M_PI / 180);
  _matrix(0,1) = -sin(angle * M_PI / 180);
  _matrix(1,0) =  sin(angle * M_PI / 180);
  _matrix(1,1) =  cos(angle * M_PI / 180);

  return _matrix;
}


cv::Mat ConvertTooRGB::applyRotation(cv::Mat img) {

   double angleTheta = getAngle();
   cv::MatIterator_<cv::Vec3b> itd, end;
   for( itd=img.begin<cv::Vec3b>(); itd!= img.end<cv::Vec3b>();++itd) {

      Eigen::Vector3d _local {(*itd)[0], (*itd)[1], (*itd)[2]};

      _local = rotatePoint((angleTheta)) * _local;
} 

return img;}