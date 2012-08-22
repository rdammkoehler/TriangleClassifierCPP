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
  };

}

#endif
