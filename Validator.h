#ifndef VALIDATOR_H
#define VALIDATOR_H
#include "Triangle.h"
#include "FloatMath.h"

namespace Triangles
{

  class Validator
  {
  public:
  Validator() : 
    math(FloatMath()) 
      {
      };
    ~Validator()
      {
      };
    bool isValid(Triangle);
    bool hasLengths(Triangle);

  private:
    float sumAngles(Triangle);
    bool hasNegativeAngles(Triangle);
    bool validAngles(Triangle);
    bool lengthIsValid(float);
    bool lengthsAreValid(Triangle);
    bool longestSideIsntTooLong(Triangle);
    bool validLengths(Triangle);
    FloatMath math;
  };

}

#endif
