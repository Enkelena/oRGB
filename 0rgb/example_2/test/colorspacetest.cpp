#include "colorspacetest.hpp"
using namespace cv;

TEST_F(ColorSpaceTest, setNormalizeImage) {
  
   std::string path = "/home/solaborate/Downloads/pot.jpg";
   cv::Mat img = cv::imread(path, cv::IMREAD_COLOR);
EXPECT_TRUE(base_.setNormalizeImage(img));
}


TEST_F(ColorSpaceTest, setLinearImage) {
  
   std::string path = "/home/solaborate/Downloads/pot.jpg";
   cv::Mat img = cv::imread(path, cv::IMREAD_COLOR);
   base_.setNormalizeImage(img);
EXPECT_TRUE(base_.setLinearImage());
}


TEST_F(ColorSpaceTest, fullRotation) {
  
   std::string path = "/home/solaborate/Downloads/pot.jpg";
   cv::Mat img = cv::imread(path, cv::IMREAD_COLOR);
   base_.setNormalizeImage(img);
   base_.setLinearImage();
EXPECT_TRUE(base_.fullRotation());
}



int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}