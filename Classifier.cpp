#include "Classifier.h"
#include "Validator.h"
#include "FloatMath.h"

using namespace Triangles;

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

bool Classifier::hasNintyDegreeAngle(Triangle triangle)
{
  FloatMath math = FloatMath();
  return math.isNinty(triangle.getAngle0()) ||
    math.isNinty(triangle.getAngle1()) ||
    math.isNinty(triangle.getAngle2());
}

bool Classifier::hasObtuseAngle(Triangle triangle)
{
  FloatMath math = FloatMath();
  return math.greaterThanNinty(triangle.getAngle0()) ||
    math.greaterThanNinty(triangle.getAngle1()) ||
    math.greaterThanNinty(triangle.getAngle2());
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
      if ( triangle.hasLengths() )
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
