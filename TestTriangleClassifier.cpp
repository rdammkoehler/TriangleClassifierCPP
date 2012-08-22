#include "Triangle.h"
#include "Classifier.h"
#include "gtest/gtest.h"

using ::Triangles::Triangle;
using ::Triangles::Classifier;

TEST(Classifier,EquilateralDetection) 
{
  int length0, length1, length2;
  length0 = length1 = length2 = 5;
  Triangle givenTriangle = Triangle(length0, length1, length2);

  Classifier::Type actualType = Classifier().classify(givenTriangle);

  EXPECT_EQ(Classifier::equilateral, actualType) << "Expected Equilateral Classification";
}

TEST(Classifier,IsoscelesDetection)
{
  int length0, length1, length2;
  length0 = length1 = 5;
  length2 = 3;
  Triangle givenTriangle = Triangle(length0, length1, length2);

  Classifier::Type actualType = Classifier().classify(givenTriangle);

  EXPECT_EQ(Classifier::isosceles, actualType) << "Expected Isosceles Classification";
}

TEST(Classifier,ScaleneDetection) 
{
  int length0, length1, length2;
  length0 = 2;
  length1 = 4;
  length2 = 3;
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
