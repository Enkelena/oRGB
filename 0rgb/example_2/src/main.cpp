#include "inversecolorpsaceadjustement.hpp"
#include "colorspaceadjustment.hpp"
#include "colorspaceadjustment.cpp"
#include "inversecolorpsaceadjustement.cpp"
using namespace cv;

int main(int argc, char *argv[]) {

   Inverse inv;
   ConvertTooRGB firstConvert;
  
   std::string path = "../../../Downloads/lena.png";
   cv::Mat img = cv::imread(path, cv::IMREAD_COLOR);
   cv::cvtColor(img, img, cv::COLOR_BGR2RGB);

  if (!img.data)
  {
      std::cout << "Image not loaded. Check path : " << path << std::endl;
      // return false;
  }
 
//---------filters here-----------------

  img = firstConvert.setFilter(img, 0.0, 0.3);
  //img=firstConvert.channelExtraction(img, firstConvert.channel::L);

  //--------------------------------------------

  cv::cvtColor(img, img, cv::COLOR_RGB2BGR);
  cv::namedWindow( "Result", cv::WINDOW_FULLSCREEN);
  cv::imshow("Result", img);  
 
  std::cout << "Press any key to close ..." << std::endl;
  cv::waitKey(0);
  cv::destroyAllWindows();
  
  return 0;
}