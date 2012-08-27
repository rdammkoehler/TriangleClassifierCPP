#ifndef VALIDATOR_H
#define VALIDATOR_H
#include "Triangle.h"

namespace Triangles
{

  class Validator
  {
  public:
    bool isValid(Triangle);
    bool isZero(float);
    bool equal(float, float);
  private:
    bool isNegative(float);
    bool isOneEighty(float);
    bool hasLengths(Triangle); //!DRY
    float sumAngles(Triangle);
    bool hasNegativeAngles(Triangle);
    bool validAngles(Triangle);
    bool lengthIsValid(float);
    bool lengthsAreValid(Triangle);
    bool longestSideIsntTooLong(Triangle);
    bool validLengths(Triangle);
  };

}

#endif
