#ifndef CLASSIFIER_H
#define CLASSIFIER_H
#include "Triangle.h"

namespace Triangles
{

  class Classifier
  {
  public:
    enum Type
    {
      equilateral, 
      isosceles, 
      scalene, 
      right, 
      obtuse, 
      acute, 
      invalid 
    };

    Classifier() 
      {
      };

    ~Classifier() 
      {
      };

    Type classify(Triangle);

  private:
    bool isZero(int);
    bool hasLengths(Triangle);
    bool hasThreeEqualSides(Triangle);
    bool hasTwoEqualSides(Triangle);
    Type classifyByLengths(Triangle);
    bool isNinty(float);
    bool greaterThanNinty(float);
    bool lessThanNinty(float);
    bool hasNintyDegreeAngle(Triangle);
    bool hasObtuseAngle(Triangle);
    Type classifyByAngles(Triangle);
    float sumAngles(Triangle);
    bool equal(float, float);
    bool isZero(float);
    bool isOneEighty(float);
    bool isNegative(float);
    bool hasNegativeAngles(Triangle);
    bool validAngles(Triangle);
    bool isNegative(int);
    bool lengthIsValid(int);
    bool lengthsAreValid(Triangle);
    bool longestSideIsntTooLong(Triangle);
    bool validLengths(Triangle);
    bool valid(Triangle);
  };

}

#endif
