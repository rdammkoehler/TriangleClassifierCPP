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
    bool isNinty(float);
    bool greaterThanNinty(float);
    bool lessThanNinty(float);
    bool valid(Triangle);
  };

}

#endif
