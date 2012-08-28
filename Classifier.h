#ifndef CLASSIFIER_H
#define CLASSIFIER_H
#include "Triangle.h"
#include "Validator.h"
#include "FloatMath.h"

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

  Classifier() : validator(Validator()), math(FloatMath())
      {	
      };

    ~Classifier() 
      {
      };

    Type classify(Triangle);

  private:
    bool hasThreeEqualSides(Triangle);
    bool hasTwoEqualSides(Triangle);
    Type classifyByLengths(Triangle);
    bool hasNintyDegreeAngle(Triangle);
    bool hasObtuseAngle(Triangle);
    Type classifyByAngles(Triangle);
    Validator validator;
    FloatMath math;
  };

}

#endif
