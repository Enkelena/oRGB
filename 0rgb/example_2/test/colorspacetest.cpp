#include "colorspacetest.hpp"

TEST_F(ColorSpaceTest, setLinearImage) {
EXPECT_TRUE(base_.setLinearImage());
}


int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}