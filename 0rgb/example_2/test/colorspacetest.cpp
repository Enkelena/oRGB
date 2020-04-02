// /**
//  * @author Mergim Halimi (m.halimi123@gmail.com)
//  * @version 0.1
//  * @date 2019-09-03
//  * 
//  * @copyright Copyright (c) 2019
//  * 
//  */
// #include "opencv_wrapper_test.hpp"

// TEST_F(OpenCvWrapperTest, SetBaseMatrix)
// {
//   const Eigen::Matrix<double, 3, 3> _local{{1, 0, 0}, 
//                                            {0, 1, 0}, 
//                                            {0, 0, 1}};

//   EXPECT_TRUE(base_.setBaseMatrix(_local));
// }


// TEST_F(OpenCvWrapperTest, GetBaseMatrix)
// {
//   const Eigen::Matrix<double, 3, 3> _local{{1, 0, 0}, 
//                                            {0, 1, 0}, 
//                                            {0, 0, 1}};

//   EXPECT_EQ(base_.getMatrix3d(), _local);
// }

// //------------------------------------------------
// TEST_F(OpenCvWrapperTest, SetTranslationMatrix)
// {
//   const Eigen::Vector2d vektori(3,3);
//   EXPECT_TRUE(base_.setTranslationMatrix(vektori));
// }


// TEST_F(OpenCvWrapperTest, TranslateBaseMatrix)
// {  
//    const Eigen::Matrix<double, 3, 3> testMatrix{{1,0,3},
//                                             {0,1,3},
//                                                 {0,0,1}};

// //const Eigen::Vector3d _local{{4, 4, 1}};
//     EXPECT_EQ(base_.getTransMatrix3d(), testMatrix);   
//  // EXPECT_EQ(testMatrix*vec, _local);                                   
// }
// //-------------------------------------------------


// TEST_F(OpenCvWrapperTest, SetScaleMatrix) {
//     const Eigen::Vector2d vektori(3,3);
//         EXPECT_TRUE(base_.setScaleMatrix(vektori));

//    // EXPECT_EQ(base_.scale(vektori), testMatrix);                                   
// }


// TEST_F(OpenCvWrapperTest, ScaleBaseMatrix)
// {  
//     const Eigen::Matrix<double, 3, 3> testMatrix{{3,0,0},
//                                             {0,3,0},
//                                                 {0,0,1}};

// //const Eigen::Vector3d _local{{4, 4, 1}};
//     EXPECT_EQ(base_.getScaleMatrix3d(), testMatrix);   
//  // EXPECT_EQ(testMatrix*vec, _local);                                   
// }



// TEST_F(OpenCvWrapperTest, SetRotate0Matrix) {
//     double angle=100;
//         EXPECT_TRUE(base_.setRotate0Matrix(angle));

//    // EXPECT_EQ(base_.scale(vektori), testMatrix);                                   
// }


// TEST_F(OpenCvWrapperTest, Rotate0BaseMatrix)  
// {  
   
//   const Eigen::Matrix<double, 3, 3> _result{{-0.17, -0.98, 0}, 
//                                             { 0.98, -0.17, 0}, 
//                                             { 0,     0,    1}};

//  EXPECT_NEAR(base_.getRotate0Matrix3d()(0,0), _result(0,0), 0.01);
//   EXPECT_NEAR(base_.getRotate0Matrix3d()(0,1), _result(0,1), 0.01);
//   EXPECT_NEAR(base_.getRotate0Matrix3d()(1,0), _result(1,0), 0.01);
//   EXPECT_NEAR(base_.getRotate0Matrix3d()(1,1), _result(1,1), 0.01);
    
//  // EXPECT_EQ(testMatrix*vec, _local);                                   
// }



// TEST_F(OpenCvWrapperTest, SetShearXmatrix)
// {
//   double d=2;
//   EXPECT_TRUE(base_.setShearXMatrix(d));
// }


// TEST_F(OpenCvWrapperTest, ShearXBaseMatrix) {
    
//     const Eigen::Matrix<double,3,3> _local{{1, 2, 0}, 
//                                            {0, 1, 0}, 
//                                            {0, 0, 1}};
//     EXPECT_EQ(base_.getShearXMatrix3d(), _local);  
//     }



// TEST_F(OpenCvWrapperTest, SetShearYmatrix)
// {
//   double d=2;
//   EXPECT_TRUE(base_.setShearYMatrix(d));
// }


// TEST_F(OpenCvWrapperTest, ShearYBaseMatrix) {
    
//     const Eigen::Matrix<double,3,3> _local{{1, 0, 0}, 
//                                            {2, 1, 0}, 
//                                            {0, 0, 1}};
//     EXPECT_EQ(base_.getShearYMatrix3d(), _local);  
//     }
                 

// TEST_F(OpenCvWrapperTest, setReflect0Matrix)
// {
//     EXPECT_TRUE(base_.setReflect0Matrix());
// }



// TEST_F(OpenCvWrapperTest, Reflect0BaseMatrix) {
//   const Eigen::Matrix<double, 3, 3> testMatrix{{-1,-0,0},
//                                             {-0,-1,0},
//                                                 {0,0,1}};

//   EXPECT_EQ(base_.getReflect0Matrix3d(), testMatrix);                                  
// }


// TEST_F(OpenCvWrapperTest, setReflectXMatrix)
// {
//     EXPECT_TRUE(base_.setReflectXMatrix());
// }



// TEST_F(OpenCvWrapperTest, ReflectXBaseMatrix) {
//   const Eigen::Matrix<double, 3, 3> testMatrix{{1,0,0},
//                                             {0,-1,0},
//                                                 {0,0,1}};

//   EXPECT_EQ(base_.getReflectXMatrix3d(), testMatrix);                                  
// }


// TEST_F(OpenCvWrapperTest, setReflectYMatrix)
// {
//     EXPECT_TRUE(base_.setReflectYMatrix());
// }



// TEST_F(OpenCvWrapperTest, ReflectYBaseMatrix) {
//   const Eigen::Matrix<double, 3, 3> testMatrix{{-1,0,0},
//                                             {0,1,0},
//                                                 {0,0,1}};

//   EXPECT_EQ(base_.getReflectYMatrix3d(), testMatrix);                                  
// }


// TEST_F(OpenCvWrapperTest, TranslatevecBaseMatrix)
// {  
//   const Eigen::Vector <double,3> res{5,4,1};
//     const Eigen::Vector <double,3> pika{2,1,1};
//     const Eigen::Matrix <double,3,3 > test_matrica = base_.getTransMatrix3d();
   
// //const Eigen::Vector3d _local{{4, 4, 1}};
//     EXPECT_EQ(base_.multiply(pika,test_matrica), res);   
//  // EXPECT_EQ(testMatrix*vec, _local);                                   
// }


// TEST_F(OpenCvWrapperTest, ScalevecBaseMatrix)
// {  
//   const Eigen::Vector <double,3> res{6,3,1};
//     const Eigen::Vector <double,3> pika{2,1,1};
//     const Eigen::Matrix <double,3,3 > test_matrica = base_.getScaleMatrix3d();
   
// //const Eigen::Vector3d _local{{4, 4, 1}};
//     EXPECT_EQ(base_.multiply(pika,test_matrica), res);   
//  // EXPECT_EQ(testMatrix*vec, _local);                                   
// }


// TEST_F(OpenCvWrapperTest, RotatevecBaseMatrix)
// {  
//   const Eigen::Vector <double,3> res{-1.32,1.79,1};
//     const Eigen::Vector <double,3> pika{2,1,1};
//     const Eigen::Matrix <double,3,3 > test_matrica = base_.getRotate0Matrix3d();
   
// //const Eigen::Vector3d _local{{4, 4, 1}};
//     EXPECT_NEAR(base_.multiply(pika,test_matrica)(0), res(0),1); 
//     EXPECT_NEAR(base_.multiply(pika,test_matrica)(1), res(1),1);
//     EXPECT_NEAR(base_.multiply(pika,test_matrica)(2), res(2),1);
//  // EXPECT_EQ(testMatrix*vec, _local);                                   
// }


// TEST_F(OpenCvWrapperTest, ShearXvecBaseMatrix)
// {  
//   const Eigen::Vector <double,3> res{4,1,1};
//     const Eigen::Vector <double,3> pika{2,1,1};
//     const Eigen::Matrix <double,3,3 > test_matrica = base_.getShearXMatrix3d();
   
// //const Eigen::Vector3d _local{{4, 4, 1}};
//     EXPECT_EQ(base_.multiply(pika,test_matrica), res);   
//  // EXPECT_EQ(testMatrix*vec, _local);                                   
// }


// TEST_F(OpenCvWrapperTest, ShearYvecBaseMatrix)
// {  
//   const Eigen::Vector <double,3> res{2,5,1};
//     const Eigen::Vector <double,3> pika{2,1,1};
//     const Eigen::Matrix <double,3,3 > test_matrica = base_.getShearYMatrix3d();
   
// //const Eigen::Vector3d _local{{4, 4, 1}};
//     EXPECT_EQ(base_.multiply(pika,test_matrica), res);   
//  // EXPECT_EQ(testMatrix*vec, _local);                                   
// }


// TEST_F(OpenCvWrapperTest, Reflect0vecBaseMatrix)
// {  
//   const Eigen::Vector <double,3> res{-2,-1,1};
//     const Eigen::Vector <double,3> pika{2,1,1};
//     const Eigen::Matrix <double,3,3 > test_matrica = base_.getReflect0Matrix3d();
   
// //const Eigen::Vector3d _local{{4, 4, 1}};
//     EXPECT_EQ(base_.multiply(pika,test_matrica), res);   
//  // EXPECT_EQ(testMatrix*vec, _local);                                   
// }


// TEST_F(OpenCvWrapperTest, ReflectXvecBaseMatrix)
// {  
//   const Eigen::Vector <double,3> res{2,-1,1};
//     const Eigen::Vector <double,3> pika{2,1,1};
//     const Eigen::Matrix <double,3,3 > test_matrica = base_.getReflectXMatrix3d();
   
// //const Eigen::Vector3d _local{{4, 4, 1}};
//     EXPECT_EQ(base_.multiply(pika,test_matrica), res);   
//  // EXPECT_EQ(testMatrix*vec, _local);                                   
// }



// TEST_F(OpenCvWrapperTest, ReflectYvecBaseMatrix)
// {  
//   const Eigen::Vector <double,3> res{-2,1,1};
//     const Eigen::Vector <double,3> pika{2,1,1};
//     const Eigen::Matrix <double,3,3 > test_matrica = base_.getReflectYMatrix3d();
   
// //const Eigen::Vector3d _local{{4, 4, 1}};
//     EXPECT_EQ(base_.multiply(pika,test_matrica), res);   
//  // EXPECT_EQ(testMatrix*vec, _local);    transform_.multiply(itd,test.getTransMatrix3d())                               
// }




// int main(int argc, char **argv) 
// {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }