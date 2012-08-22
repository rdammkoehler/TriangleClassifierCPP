#include "Classifier.h"
#include <math.h>
#include <iostream>

using namespace Triangles;
using namespace std;

Classifier::Type Classifier::classify(Triangle triangle)
{
  Classifier::Type type = invalid;
  if ( valid(triangle) ) 
    {
      if (triangle.getLength0() != 0 &&
	  triangle.getLength1() != 0 &&
	  triangle.getLength2() != 0)
	{
	  if (triangle.getLength0() == triangle.getLength1() &&
	      triangle.getLength0() == triangle.getLength2())
	    {
	      type = equilateral;
	    } 
	  else if (triangle.getLength0() == triangle.getLength1() ||
		   triangle.getLength0() == triangle.getLength2() ||
		   triangle.getLength1() == triangle.getLength2())
	    {
	      type = isosceles;
	    } 
	  else 
	    {
	      type = scalene;
	    }
	} 
      else
	{
	  if (isNinty(triangle.getAngle0()) ||
	      isNinty(triangle.getAngle1()) ||
	      isNinty(triangle.getAngle2()))
	    {
	      type = right;
	    }
	  else if (greaterThanNinty(triangle.getAngle0()) ||
		   greaterThanNinty(triangle.getAngle1()) ||
		   greaterThanNinty(triangle.getAngle2()))
	    {
	      type = obtuse;
	    }
	  else {
	    type = acute;
	  }
	}
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

bool Classifier::valid(Triangle triangle)
{
  bool valid = true;
  valid &= validAngles(triangle);
  if ( hasLengths(triangle) )
    {
      valid &= lengthsAreValid(triangle);
 
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
      valid &= longest < shortSideSum;
    }
  return valid;
}
