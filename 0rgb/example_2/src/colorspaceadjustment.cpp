#include "colorspaceadjustment.hpp"

cv::Mat ConvertTooRGB::normalize(cv::Mat img)
{
 cv::Mat img1 = img.clone();
    img1.convertTo(img1, CV_64FC3);
    double r{0},b{0},g{0};

    cv::MatIterator_<cv::Vec3d> itd = img1.begin<cv::Vec3d>(), itd_end = img1.end<cv::Vec3d>();
    for(int i = 0; itd != itd_end; ++itd,++i)
    {          
      r = pow((static_cast<double>((*itd)(0)) / 255.0),(1/2.2));
      g = pow((static_cast<double>((*itd)(1)) / 255.0),(1/2.2));
      b = pow((static_cast<double>((*itd)(2)) / 255.0),(1/2.2));

      (*itd)[0] = r;
      (*itd)[1] = g;
      (*itd)[2] = b;
    }   
    return img1;
} 

cv::Mat ConvertTooRGB::linearTransform(cv::Mat img) 
{
   Eigen::Matrix3d linear_matrix;

   linear_matrix << 0.2990, 0.5870, 0.1140, 
                       0.5000, 0.5000, -1.0000,
                       0.8660, -0.8660, 0.0000;

   double r{0},b{0},g{0};
   cv::Mat img1 = img.clone();

   cv::MatIterator_<cv::Vec3d> itd, end;
   for( itd=img1.begin<cv::Vec3d>(); itd!= img1.end<cv::Vec3d>();++itd) {

      r= (*itd)[0];
      g= (*itd)[1];
      b= (*itd)[2];

      Eigen::Vector3d _local {r,g,b};

      _local = linear_matrix * _local;

      (*itd)[0]=(_local[0]);        
      (*itd)[1]=(_local[1]);
      (*itd)[2]=(_local[2]);
   }
   return img1;
}


Eigen::Matrix3d ConvertTooRGB::rotatePoint(double angle)
 {
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


cv::Mat ConvertTooRGB::fullRotation(cv::Mat img) 
{
   cv::Mat img1 = img.clone();
   double thetaAngle=0;
   double r{0},b{0},g{0};

   cv::MatIterator_<cv::Vec3d> itd, end;
   for(itd=img1.begin<cv::Vec3d>(); itd!= img1.end<cv::Vec3d>();++itd) 
   {
      r=(*itd)[0];
      g=(*itd)[1];
      b=(*itd)[2];
      double theta = atan2(b, g);
      double newTheta=0;
   
      if(theta< M_PI / 3) {
         newTheta = (3/2)*theta;
      }

      if((theta>= (M_PI /3)) && (theta <=(5*M_PI/3))) {
         newTheta = (M_PI/2 + 3/4*(theta-M_PI/3));   
      } 

      if((theta> 5*M_PI / 3) && (theta <(2*M_PI)) ) {
         newTheta = (3/2)*theta;
      }

      thetaAngle=(newTheta-theta);
      // std::cout<<("kendi:", thetaAngle)<<std::endl;
 
      Eigen::Vector3d _local {r,g,b};
      _local = (rotatePoint(thetaAngle) * _local);

      (*itd)[0]=(_local[0]);        
      (*itd)[1]=(_local[1]);
      (*itd)[2]=(_local[2]);
   }
         //  img.convertTo(img, CV_8UC3);
   return img1;
}


// cv::Mat ConvertTooRGB::filter(double cyb, double crg, cv::Mat img) {

//    cv::Mat img1 = img.clone();
//    cv::MatIterator_<cv::Vec3d> itd, end;
//    for( itd=img1.begin<cv::Vec3d>(); itd!= img1.end<cv::Vec3d>();++itd) 
//    { 
//       if(((*itd)[2] -=cyb)<-1)
//       {
//          (*itd)[2] =-1.0;
//       }
         
//       if(((*itd)[2] -=cyb)>1) 
//       {
//          (*itd)[2] =1.0;
//       }

//       if(((*itd)[1] -=crg)<-1)
//       {
//          (*itd)[1] =-1.0;
//       }

//       if(((*itd)[1] -=crg)>1) 
//       {
//          (*itd)[1] =1.0;
//       }
//    }
//    return img1;
// }

cv::Mat ConvertTooRGB::filter(double cyb, double crg, cv::Mat img) {

   cv::Mat img1 = img.clone();
   cv::MatIterator_<cv::Vec3d> itd, end;
   for( itd=img1.begin<cv::Vec3d>(); itd!= img1.end<cv::Vec3d>();++itd) 
   { 


      if(((*itd)[2] -=cyb)<-1)
      {
         (*itd)[2] =-1.0;
      }
         
      if(((*itd)[2] -=cyb)>1) 
      {
         (*itd)[2] =1.0;
      }

      if(((*itd)[1] -=crg)<-1)
      {
         (*itd)[1] =-1.0;
      }

      if(((*itd)[1] -=crg)>1) 
      {
         (*itd)[1] =1.0;
      }
   }
   return img1;
}


cv::Mat ConvertTooRGB::channelExtraction( cv::Mat img, channel c) { 

   cv::Mat img1 = img.clone();
   cv::MatIterator_<cv::Vec3d> itd, end;
   for( itd=img1.begin<cv::Vec3d>(); itd!= img1.end<cv::Vec3d>();++itd) 
   { 
     // ConvertTooRGB::channel c; 

      switch (c)
      {
      case  L:
       (*itd)[0] =  (*itd)[0];
       (*itd)[1]=0;
       (*itd)[2]=0;
         break;

        case  Cyb:
       (*itd)[0] =  0;
       (*itd)[1]=(*itd)[1];
       (*itd)[2]=0;
         break;

       case  Crg:
       (*itd)[0] = 0;
       (*itd)[1]=0;
       (*itd)[2]=(*itd)[2];
         break;

      default:
      std::cout << "Invalid Selection\n";
         break;
      }
}    
return img1; }