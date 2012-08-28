#ifndef VALIDATOR_H
#define VALIDATOR_H
#include "Triangle.h"

namespace Triangles
{

  class Validator
  {
  public:
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
  };

}

#endif
