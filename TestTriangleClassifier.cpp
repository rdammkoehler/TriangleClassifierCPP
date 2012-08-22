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
  Classifier classifier = Classifier();

  Classifier::Type actualType = classifier.classify(givenTriangle);
 
  EXPECT_EQ(Classifier::equilateral, actualType);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
