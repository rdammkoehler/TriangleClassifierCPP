#include "Classifier.h"
#include <math.h>
#include <iostream>

using namespace Triangles;
using namespace std;

bool Classifier::isZero(int d)
{
  return 0 == d;
}

bool Classifier::hasLengths(Triangle triangle)
{
  return !(isZero(triangle.getLength0()) &&
	   isZero(triangle.getLength1()) &&
	   isZero(triangle.getLength2()));
}

bool Classifier::hasThreeEqualSides(Triangle triangle) 
{
  return triangle.getLength0() == triangle.getLength1() &&
    triangle.getLength0() == triangle.getLength2();
}

bool Classifier::hasTwoEqualSides(Triangle triangle)
{
  return triangle.getLength0() == triangle.getLength1() ||
    triangle.getLength0() == triangle.getLength2() ||
    triangle.getLength1() == triangle.getLength2();
}

Classifier::Type Classifier::classifyByLengths(Triangle triangle)
{
  Classifier::Type type = Classifier::invalid;
  if (hasThreeEqualSides(triangle))
    {
      type = Classifier::equilateral;
    } 
  else if (hasTwoEqualSides(triangle))
    {
      type = Classifier::isosceles;
    } 
  else 
    {
      type = Classifier::scalene;
    }
  return type;
}

bool Classifier::isNinty(float angle)
{
  return fabs(90.0f - angle) < 0.0001;
}

bool Classifier::greaterThanNinty(float angle)
{
  return angle > 90.0f;
}

bool Classifier::lessThanNinty(float angle) 
{
  return angle < 90.0f;
}

bool Classifier::hasNintyDegreeAngle(Triangle triangle)
{
  return isNinty(triangle.getAngle0()) ||
    isNinty(triangle.getAngle1()) ||
    isNinty(triangle.getAngle2());
}

bool Classifier::hasObtuseAngle(Triangle triangle)
{
  return greaterThanNinty(triangle.getAngle0()) ||
    greaterThanNinty(triangle.getAngle1()) ||
    greaterThanNinty(triangle.getAngle2());
}

Classifier::Type Classifier::classifyByAngles(Triangle triangle)
{
  Classifier::Type type = Classifier::invalid;
  if (hasNintyDegreeAngle(triangle))
    {
      type = Classifier::right;
    }
  else if (hasObtuseAngle(triangle))
    {
      type = Classifier::obtuse;
    }
  else 
    {
      type = Classifier::acute;
    }
  return type;
}

float Classifier::sumAngles(Triangle triangle)
{
  return triangle.getAngle0() + triangle.getAngle1() + triangle.getAngle2();
}

bool Classifier::equal(float a, float b) 
{
  return fabs( a - b ) < 0.0001;
}

bool Classifier::isZero(float f) 
{
  return equal(0.0f, f);
}

bool Classifier::isOneEighty(float f) 
{
  return equal(180.0f, f);
}

bool Classifier::isNegative(float f)
{
  return 0.0f > f;
}

bool Classifier::hasNegativeAngles(Triangle triangle)
{
  return isNegative(triangle.getAngle0()) || isNegative(triangle.getAngle1()) || isNegative(triangle.getAngle2());
}

bool Classifier::validAngles(Triangle triangle)
{
  float sumOfAngles = sumAngles(triangle);
  return !hasNegativeAngles(triangle) && ( isZero(sumOfAngles) || isOneEighty(sumOfAngles) );
}

bool Classifier::isNegative(int d)
{
  return 0 > d;
}

bool Classifier::lengthIsValid(int length) 
{
  return !isZero(length) && !isNegative(length);
}

bool Classifier::lengthsAreValid(Triangle triangle)
{
  bool valid = true;
  valid &= lengthIsValid(triangle.getLength0());
  valid &= lengthIsValid(triangle.getLength1());
  valid &= lengthIsValid(triangle.getLength2());
  return valid;
}

bool Classifier::longestSideIsntTooLong(Triangle triangle)
{
  int longest = 0;
  int shortSideSum = 0;
  if (longest < triangle.getLength0())
    {
      longest = triangle.getLength0();
      shortSideSum = triangle.getLength1() + triangle.getLength2();
    }
  if (longest < triangle.getLength1())
    {
      longest = triangle.getLength1();
      shortSideSum = triangle.getLength0() + triangle.getLength2();
    }
  if (longest < triangle.getLength2())
    {
      longest = triangle.getLength2();
      shortSideSum = triangle.getLength0() + triangle.getLength1();
    }
  return longest < shortSideSum;
}

bool Classifier::validLengths(Triangle triangle) 
{
  bool valid = true;
  if ( hasLengths(triangle) )
    {
      valid &= lengthsAreValid(triangle);
      valid &= longestSideIsntTooLong(triangle);
    }
  return valid;
}

bool Classifier::valid(Triangle triangle)
{
  return validAngles(triangle) && validLengths(triangle);
}

Classifier::Type Classifier::classify(Triangle triangle)
{
  Classifier::Type type = invalid;
  if ( valid(triangle) ) 
    {
      if (hasLengths(triangle))
	{
	  type = classifyByLengths(triangle);
	} 
      else
	{
	  type = classifyByAngles(triangle);
	}
    }
  return type;
}
