#include "Validator.h"
#include <math.h>
#include <float.h>

using namespace Triangles;

bool Validator::equal(float a, float b) 
{
  return fabs( a - b ) < FLT_EPSILON;
}

bool Validator::isZero(float f) 
{
  return equal(0.0f, f);
}

bool Validator::isNegative(float d)
{
  return 0.0f > d;
}

bool Validator::isOneEighty(float f) 
{
  return equal(180.0f, f);
}

bool Validator::hasNegativeAngles(Triangle triangle)
{
  return isNegative(triangle.getAngle0()) || isNegative(triangle.getAngle1()) || isNegative(triangle.getAngle2());
}

float Validator::sumAngles(Triangle triangle)
{
  return triangle.getAngle0() + triangle.getAngle1() + triangle.getAngle2();
}

bool Validator::validAngles(Triangle triangle)
{
  float sumOfAngles = sumAngles(triangle);
  return !hasNegativeAngles(triangle) && ( isZero(sumOfAngles) || isOneEighty(sumOfAngles) );
}

bool Validator::lengthIsValid(float length) 
{
  return !isZero(length) && !isNegative(length);
}

bool Validator::lengthsAreValid(Triangle triangle)
{
  bool valid = true;
  valid &= lengthIsValid(triangle.getLength0());
  valid &= lengthIsValid(triangle.getLength1());
  valid &= lengthIsValid(triangle.getLength2());
  return valid;
}

bool Validator::longestSideIsntTooLong(Triangle triangle)
{
  float longest = FLT_MIN;
  float shortSideSum = FLT_MIN;
  if ( longest < triangle.getLength0() )
    {
      longest = triangle.getLength0();
      shortSideSum = triangle.getLength1() + triangle.getLength2();
    }
  if ( longest < triangle.getLength1() )
    {
      longest = triangle.getLength1();
      shortSideSum = triangle.getLength0() + triangle.getLength2();
    }
  if ( longest < triangle.getLength2() )
    {
      longest = triangle.getLength2();
      shortSideSum = triangle.getLength0() + triangle.getLength1();
    }
  return longest < shortSideSum;
}

bool Validator::validLengths(Triangle triangle) 
{
  bool valid = true;
  if ( triangle.hasLengths() ) 
    {
      valid &= lengthsAreValid(triangle);
      valid &= longestSideIsntTooLong(triangle);
    }
  return valid;
}

bool Validator::isValid(Triangle triangle)
{
  return validAngles(triangle) && validLengths(triangle);
}
