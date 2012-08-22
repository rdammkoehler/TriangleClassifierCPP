#include "Triangle.h"
#include "Classifier.h"
#include "gtest/gtest.h"
#include <iostream>

using ::Triangles::Triangle;
using ::Triangles::Classifier;
using namespace std;

Classifier::Type classify(int length0, int length1, int length2) 
{
  return Classifier().classify(Triangle(length0, length1, length2));
}

Classifier::Type classify(float angle0, float angle1, float angle2)
{
  return Classifier().classify(Triangle(angle0, angle1, angle2));
}

TEST(Classifier,EquilateralDetection) 
{
  EXPECT_EQ(Classifier::equilateral, classify(5, 5, 5)) << "Expected Equilateral Classification";
}

TEST(Classifier,IsoscelesDetection)
{
  EXPECT_EQ(Classifier::isosceles, classify(5, 5, 3)) << "Expected Isosceles Classification";
}

TEST(Classifier,ScaleneDetection) 
{
  EXPECT_EQ(Classifier::scalene, classify(2, 4, 3)) << "Expected Scalene Classification";
}

TEST(Classifier,RightTriangleDetection)
{
  EXPECT_EQ(Classifier::right, classify(90.0f, 45.0f, 45.0f)) << "Expected Right Triangle Classification";
}

TEST(Classifier,ObtuseTriangleDetection)
{
  EXPECT_EQ(Classifier::obtuse, classify(100.0f, 40.0f, 40.0f)) << "Expected Obtuse Triangle Classification";
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
