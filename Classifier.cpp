#include "Classifier.h"
#include <math.h>

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

bool Classifier::valid(Triangle triangle)
{
  bool valid = true;
  float sumOfAngles = triangle.getAngle0() + triangle.getAngle1() + triangle.getAngle2();
  valid &= ( fabs( 0.0f - sumOfAngles ) < 0.0001 || fabs( 180.0f - sumOfAngles ) < 0.0001 );
  if ( triangle.getLength0() != 0 ||
       triangle.getLength1() != 0 ||
       triangle.getLength2() != 0)
    {
      valid &= triangle.getLength0() > 0;
      valid &= triangle.getLength1() > 0;
      valid &= triangle.getLength2() > 0;
    }
  return valid;
}
