#include "Classifier.h"
#include <math.h>
#include <iostream>

using namespace Triangles;
using namespace std;

bool isZero(int d)
{
  return 0 == d;
}

bool hasLengths(Triangle triangle)
{
  return !(isZero(triangle.getLength0()) &&
	   isZero(triangle.getLength1()) &&
	   isZero(triangle.getLength2()));
}

Classifier::Type classifyByLengths(Triangle triangle)
{
  Classifier::Type type = Classifier::invalid;
  if (triangle.getLength0() == triangle.getLength1() &&
      triangle.getLength0() == triangle.getLength2())
    {
      type = Classifier::equilateral;
    } 
  else if (triangle.getLength0() == triangle.getLength1() ||
	   triangle.getLength0() == triangle.getLength2() ||
	   triangle.getLength1() == triangle.getLength2())
    {
      type = Classifier::isosceles;
    } 
  else 
    {
      type = Classifier::scalene;
    }
  return type;
}

bool isNinty(float angle)
{
  return fabs(90.0f - angle) < 0.0001;
}

bool greaterThanNinty(float angle)
{
  return angle > 90.0f;
}

bool lessThanNinty(float angle) 
{
  return angle < 90.0f;
}

bool hasNintyDegreeAngle(Triangle triangle)
{
  return isNinty(triangle.getAngle0()) ||
    isNinty(triangle.getAngle1()) ||
    isNinty(triangle.getAngle2());
}

bool hasObtuseAngle(Triangle triangle)
{
  return greaterThanNinty(triangle.getAngle0()) ||
    greaterThanNinty(triangle.getAngle1()) ||
    greaterThanNinty(triangle.getAngle2());
}

Classifier::Type classifyByAngles(Triangle triangle)
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

float sumAngles(Triangle triangle)
{
  return triangle.getAngle0() + triangle.getAngle1() + triangle.getAngle2();
}

bool equal(float a, float b) 
{
  return fabs( a - b ) < 0.0001;
}

bool isZero(float f) 
{
  return equal(0.0f, f);
}

bool isOneEighty(float f) 
{
  return equal(180.0f, f);
}

bool validAngles(Triangle triangle)
{
  float sumOfAngles = sumAngles(triangle);
  return ( isZero(sumOfAngles) || isOneEighty(sumOfAngles) );
}

bool isNegative(int d)
{
  return 0 > d;
}

bool lengthIsValid(int length) 
{
  return !isZero(length) && !isNegative(length);
}

bool lengthsAreValid(Triangle triangle)
{
  bool valid = true;
  valid &= lengthIsValid(triangle.getLength0());
  valid &= lengthIsValid(triangle.getLength1());
  valid &= lengthIsValid(triangle.getLength2());
  return valid;
}

bool longestSideIsntTooLong(Triangle triangle)
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

bool validLengths(Triangle triangle) 
{
  bool valid = true;
  if ( hasLengths(triangle) )
    {
      valid &= lengthsAreValid(triangle);
      valid &= longestSideIsntTooLong(triangle);
    }
  return valid;
}

bool valid(Triangle triangle)
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
