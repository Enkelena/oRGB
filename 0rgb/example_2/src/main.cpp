#include "colorspaceadjustment.hpp"
#include <iostream>
#include <Eigen/Dense>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "colorspaceadjustment.cpp"
using namespace cv;
#include <unsupported/Eigen/MatrixFunctions>

int main(int argc, char *argv[]) {


   ConvertTooRGB test;

   std::string path = "/home/solaborate/Downloads/testim.png";
   cv::Mat img = cv::imread(path, cv::IMREAD_COLOR);



//Check if image is empty or is not in three channel colorspace
  if (!img.data)
  {
      std::cout << "Image not loaded. Check path : " << path << std::endl;
      // return false;
  }
 
 //------------------------------------------------------
  // functions here...


cv::MatIterator_<cv::Vec3b> itd=img.begin<cv::Vec3b>(), itd_end=img.end<cv::Vec3b>();
for(double i = 0;  itd !=itd_end; ++itd, ++i) 
{

Eigen::Vector3d _local ((*itd)[0], (*itd)[1], (*itd)[2]);


//itd = test.multiply(pon,test.getMatrix3d());

  double sum =  (*itd)[0] +  (*itd)[1] + (*itd)[2];

   (*itd)[0] =(_local)[0]/sum*255; //blue
   (*itd)[1] =(_local)[1]/sum*255; //green   
   (*itd)[2] =(_local)[2]/sum*255; //red

  // (*itd)[0] = test.nonlinearity(_local)[0]; //blue
  //  (*itd)[1] = test.nonlinearity(_local)[1]; //green   
  //  (*itd)[2] = test.nonlinearity(_local)[2]; //red


  (*itd)[0] = test.linearTransform(_local)[0]; //blue
   (*itd)[1] = test.linearTransform(_local)[1]; //green   
   (*itd)[2] = test.linearTransform(_local)[2]; //red

  
}
//--------------------------------------------------------
  cv::namedWindow( "Result", cv::WINDOW_FULLSCREEN);
  //reducing_color(img);
  cv::imshow("Result", img);  
 
 // reducing_color(img);
  std::cout << "Press any key to close ..." << std::endl;
  cv::waitKey(0);
  cv::destroyAllWindows();
 
  return 0;

}
 