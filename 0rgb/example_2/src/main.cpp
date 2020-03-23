#include "inversecolorpsaceadjustement.hpp"
#include "colorspaceadjustment.hpp"
#include "colorspaceadjustment.cpp"
#include "inversecolorpsaceadjustement.cpp"

using namespace cv;



int main(int argc, char *argv[]) {

   Inverse inv;

   ConvertTooRGB firstConvert;
  
   std::string path = "/home/solaborate/Downloads/lena.png";
   cv::Mat img = cv::imread(path, cv::IMREAD_COLOR);

//Check if image is empty or is not in three channel colorspace
  if (!img.data)
  {
      std::cout << "Image not loaded. Check path : " << path << std::endl;
      // return false;
  }
 
 //------------------------------------------------------
  //functions here...
  img=firstConvert.normalize(img);
  img =firstConvert.linearTransform(img);
  // img=firstConvert.fullRotation(img);  
  // img=inv.fullRotation(img);


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