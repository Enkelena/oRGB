// //Trackbar for changing Intensity Values of an Image
// #include <opencv2/core/core.hpp>
// #include <opencv2/highgui/highgui.hpp>
// #include "colorspaceadjustment.hpp"

// using namespace cv;
  
// /// Global Variables
// const int intensity_slider_max = 100;
// const int intensity_slider_min = -100;

// int slider_value=0;
// int slider_value1=0;

// /// Matrices to store images
// Mat src1,dst;
 
// //Callback Function for Trackbar
// static void on_trackbar( int, void* )
// {
//  dst=src1+slider_value+slider_value1;
//  imshow("Intensity Change", dst); 
// }
 
// int main( int argc, char** argv )
// {
//  /// Read image ( same size, same type )
//  src1 = imread("/home/solaborate/Downloads/pot.jpg",cv::IMREAD_COLOR);
  
//  if( !src1.data ) { printf("Error loading src1 \n"); return -1; };
 
//  /// Create Windows
//  namedWindow("Intensity Change", 1);
 
//  ///Create Trackbar
// createTrackbar( "Intensity", "Intensity Change", &slider_value, intensity_slider_max, on_trackbar );
// createTrackbar( "Intensity2", "Intensity Change", &slider_value1, intensity_slider_max, on_trackbar );

// setTrackbarMin("Intensity", "Intensity Change",-100);
// setTrackbarMin("Intensity2", "Intensity Change",-100);

//  /// trackbar on_change function
// on_trackbar( slider_value, 0 );
// on_trackbar( slider_value1, 0 );

 
//  /// Wait until user press some key
//  waitKey(0);
//  return 0;
// }

 //Trackbar for changing Intensity Values of an Image
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "inversecolorpsaceadjustement.hpp"
#include "colorspaceadjustment.hpp"
#include "colorspaceadjustment.cpp"
#include "inversecolorpsaceadjustement.cpp"
using namespace cv;
  
// /// Global Variables
// const int intensity_slider_max = 100;

// int slider_value=0;
// int slider_value1=0;

// /// Matrices to store images
// Mat src1,dst;
 
// //Callback Function for Trackbar
// static void on_trackbar( int, void* )
// {
//     dst=src1+slider_value+slider_value1;
//     imshow("Intensity Change", dst); 
// }
 
// int main( int argc, char** argv )
// {
//     /// Read image ( same size, same type )
//     src1 = imread("/home/solaborate/Downloads/pot.jpg",cv::IMREAD_COLOR);
    
//     if( !src1.data ) { printf("Error loading src1 \n"); return -1; };
    
//     /// Create Windows
//     namedWindow("Intensity Change", 1);
    
//     ///Create Trackbar
//     createTrackbar( "Intensity", "Intensity Change", &slider_value, intensity_slider_max, on_trackbar );
//     createTrackbar( "Intensity2", "Intensity Change", &slider_value1, intensity_slider_max, on_trackbar );

//     setTrackbarMin("Intensity", "Intensity Change",-100);
//     setTrackbarMin("Intensity2", "Intensity Change",-100);

//     /// trackbar on_change function
//     on_trackbar( slider_value, 0 );
//     on_trackbar( slider_value1, 0 );
    
//     /// Wait until user press some key
//     waitKey(0);
//     return 0;
// }

// #include "convert_colorspace.hpp"
// #include "cv_image.hpp"
// #include "color_adjustment.hpp"
// #include <opencv2/imgcodecs.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "inversecolorpsaceadjustement.hpp"
#include "colorspaceadjustment.hpp"
#include "colorspaceadjustment.cpp"
#include "inversecolorpsaceadjustement.cpp"
using namespace cv;

Inverse inv;

ConvertTooRGB firstConvert; 
const double slider_max = 100;
int slider,slider1;
double yb,rg;
Mat dst;

  
   std::string path1 = "/home/solaborate/Downloads/pot.jpg";
   cv::Mat img = cv::imread(path1, cv::IMREAD_COLOR);
   //cv::cvtColor(img, img, cv::COLOR_BGR2RGB);

//ConvertTooRGB adjust;
//ColorAdjustment filter;
// std::string path = "/home/solaborate/Downloads/image.png";
// std::string path2 = "/home/solaborate/Downloads/moroccan_pots.jpg";

static void on_trackbar(int, void*)
{
    yb = static_cast<double> (slider )/ slider_max;
    rg = static_cast<double> (slider1) / slider_max;
    // filter.setImgPath(path1);
    // img = filter.getImg();
   // img = adjust.filter(yb, rg, img );
cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
   img=firstConvert.normalize(img);
  img =firstConvert.linearTransform(img);
  img=firstConvert.fullRotation(img);  
  img = firstConvert.filter(yb, rg, img);
  img=inv.fullRotation(img);
  img = inv.linearTransform(img);
   cv::cvtColor(img, img, cv::COLOR_RGB2BGR);
    imshow("Image", img);
}

int main(int argc, char **argv)
{
    slider = 0;
    slider1 = 0;
    cv::namedWindow("Image",1);

    cv::createTrackbar("Cyb","Image", (&slider), (slider_max), on_trackbar);
    cv::createTrackbar("Crg","Image", (&slider1), (slider_max), on_trackbar);

    cv::setTrackbarMin("Cyb","Image", -100);
    cv::setTrackbarMin("Crg","Image", -100);

    on_trackbar(slider,0);
     on_trackbar(slider1,0);

    cv::waitKey(0);

    
    return 0;
} 