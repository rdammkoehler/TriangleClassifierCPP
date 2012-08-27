#include "Classifier.h"
#include "Validator.h"

using namespace Triangles;

bool Classifier::hasLengths(Triangle triangle)
{
  return !( validator.isZero(triangle.getLength0()) &&
	    validator.isZero(triangle.getLength1()) &&
	    validator.isZero(triangle.getLength2()) );
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
  if ( hasThreeEqualSides(triangle) )
    {
      type = Classifier::equilateral;
    } 
  else if ( hasTwoEqualSides(triangle) )
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
  return validator.equal(90.0f, angle);
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
  if ( hasNintyDegreeAngle(triangle) )
    {
      type = Classifier::right;
    }
  else if ( hasObtuseAngle(triangle) )
    {
      type = Classifier::obtuse;
    }
  else 
    {
      type = Classifier::acute;
    }
  return type;
}

Classifier::Type Classifier::classify(Triangle triangle)
{
  Classifier::Type type = invalid;
  if ( validator.isValid(triangle) ) 
    {
      if ( hasLengths(triangle) )
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
