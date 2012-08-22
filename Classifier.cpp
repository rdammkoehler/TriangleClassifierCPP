#include "Classifier.h"
#include <iostream>

using namespace Triangles;
using namespace std;

Classifier::Type Classifier::classify(Triangle triangle)
{
  Classifier::Type type = invalid;
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
    }
  return type;
}

bool Classifier::isNinty(float angle)
{
  return true;
}

bool Classifier::greaterThanNinty(float angle)
{
  return angle > 90.0f;
}

bool Classifier::lessThanNinty(float angle) 
{
  return angle < 90.0f;
}
