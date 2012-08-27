#ifndef CLASSIFIER_H
#define CLASSIFIER_H
#include "Triangle.h"
#include "Validator.h"

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
	validator = Validator();
      };

    ~Classifier() 
      {
      };

    Type classify(Triangle);

  private:
    bool hasThreeEqualSides(Triangle);
    bool hasTwoEqualSides(Triangle);
    Type classifyByLengths(Triangle);
    bool isNinty(float);
    bool greaterThanNinty(float);
    bool lessThanNinty(float);
    bool hasNintyDegreeAngle(Triangle);
    bool hasObtuseAngle(Triangle);
    Type classifyByAngles(Triangle);
    Validator validator;
  };

}

#endif
