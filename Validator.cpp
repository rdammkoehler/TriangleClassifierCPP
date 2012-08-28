#include "Validator.h"
#include <float.h>

using namespace Triangles;

bool Validator::hasNegativeAngles(Triangle triangle)
{
  return math.isNegative(triangle.getA()) || 
         math.isNegative(triangle.getB()) || 
         math.isNegative(triangle.getC());
}

float Validator::sumAngles(Triangle triangle)
{
  return triangle.getA() + triangle.getB() + triangle.getC();
}

bool Validator::validAngles(Triangle triangle)
{
  float sumOfAngles = sumAngles(triangle);
  return !hasNegativeAngles(triangle) && 
         ( math.isZero(sumOfAngles) || 
           math.isOneEighty(sumOfAngles) 
         );
}

bool Validator::lengthIsValid(float length) 
{
  return !math.isZero(length) && 
         !math.isNegative(length);
}

bool Validator::longestSideIsntTooLong(Triangle triangle)
{
  float longest = FLT_MIN;
  float shortSideSum = FLT_MIN;
  if ( longest < triangle.geta() )
    {
      longest = triangle.geta();
      shortSideSum = triangle.getb() + triangle.getc();
    }
  if ( longest < triangle.getb() )
    {
      longest = triangle.getb();
      shortSideSum = triangle.geta() + triangle.getc();
    }
  if ( longest < triangle.getc() )
    {
      longest = triangle.getc();
      shortSideSum = triangle.geta() + triangle.getb();
    }
  return longest < shortSideSum;
}

bool Validator::lengthsAreValid(Triangle triangle)
{
  bool valid = true;
  valid &= lengthIsValid(triangle.geta());
  valid &= lengthIsValid(triangle.getb());
  valid &= lengthIsValid(triangle.getc());
  valid &= longestSideIsntTooLong(triangle);
  return valid;
}

bool Validator::hasLengths(Triangle triangle) 
{
  return !( math.isZero(triangle.geta()) &&
	    math.isZero(triangle.getb()) &&
	    math.isZero(triangle.getc()) );
}

bool Validator::validLengths(Triangle triangle) 
{
  return !hasLengths(triangle) || lengthsAreValid(triangle);
}

bool Validator::isValid(Triangle triangle)
{
  return validAngles(triangle) && validLengths(triangle);
}
