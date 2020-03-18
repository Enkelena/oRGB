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

   std::string path = "/home/solaborate/Downloads/lena.png";
   cv::Mat img = cv::imread(path, cv::IMREAD_COLOR);



//Check if image is empty or is not in three channel colorspace
  if (!img.data)
  {
      std::cout << "Image not loaded. Check path : " << path << std::endl;
      // return false;
  }
 
 //------------------------------------------------------
  // functions here...
  img=test.normalize(img);
  img =linearTransform(img);
  test.getNewangle(img);  
  img=test.applyRotation(img);
  

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
 