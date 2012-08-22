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

TEST(Classifier,AcuteTriangleDetection)
{
  EXPECT_EQ(Classifier::acute, classify(80.0f, 50.0f, 50.f)) << "Expected Acute Triangle Classification";
}

TEST(Classifier,ValidationFailsWithTooMuchAngle)
{
  EXPECT_EQ(Classifier::invalid, classify(100.0f, 100.f, 100.0f)) << "Expected Invalid Classification, total angle > 180 degrees";
}

TEST(Classifier,ValidationFailsWithTooLittleAngle)
{
  EXPECT_EQ(Classifier::invalid, classify(2.0f, 4.0f, 5.0f)) << "Expected Invalid Classification, total angle < 180 degrees";
}

TEST(Classifier,ValidationFailsWithZeroLengthSide0)
{
  EXPECT_EQ(Classifier::invalid, classify(0, 1, 2)) << "Expected Invalid Classification, side length of zero";
}

TEST(Classifier,ValidationFailsWithZeroLengthSide1)
{
  EXPECT_EQ(Classifier::invalid, classify(1, 0, 2)) << "Expected Invalid Classification, side length of zero";
}

TEST(Classifier,ValidationFailsWithZeroLengthSide2)
{
  EXPECT_EQ(Classifier::invalid, classify(1, 2, 0)) << "Expected Invalid Classification, side length of zero";
}

TEST(Classifier,ValidationFailsIfLength0IsNegative)
{
  EXPECT_EQ(Classifier::invalid, classify(-2, 2, 2)) << "Expected Invalid Classification, side length is negative";
}

TEST(Classifier,ValidationFailsIfLength1IsNegative)
{
  EXPECT_EQ(Classifier::invalid, classify(2, -2, 2)) << "Expected Invalid Classification, side length is negative";
}

TEST(Classifier,ValidationFailsIfLength2IsNegative)
{
  EXPECT_EQ(Classifier::invalid, classify(2, 2, -2)) << "Expected Invalid Classification, side length is negative";
}

TEST(Classifier,ValidationFailsIfLengthsAreNegative)
{
  EXPECT_EQ(Classifier::invalid, classify(-2, -2, -2)) << "Expected Invalid Classification, side length is negative";
}

TEST(Classifier,ValidationFailsWhenLongestSideIsLongerThanShorterSidesSum)
{
  EXPECT_EQ(Classifier::invalid, classify(9, 5, 3)) << "Expected Invalid Classification, longest side is longer than the sum of the shorter sides";
}

TEST(Classifier,ValidationFailsWhenLongestSideIsEqualToShorterSidesSum)
{
  EXPECT_EQ(Classifier::invalid, classify(8, 5, 3)) << "Expected Invalid Classification, longest side is equal to the sum of the shorter sides";
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
