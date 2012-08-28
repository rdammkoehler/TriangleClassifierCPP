#include "Classifier.h"
#include "Validator.h"

using namespace Triangles;

bool Classifier::hasThreeEqualSides(Triangle triangle) 
{
  return triangle.geta() == triangle.getb() &&
    triangle.geta() == triangle.getc();
}

bool Classifier::hasTwoEqualSides(Triangle triangle)
{
  return triangle.geta() == triangle.getb() ||
    triangle.geta() == triangle.getc() ||
    triangle.getb() == triangle.getc();
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
  return math.isNinty(triangle.getA()) ||
    math.isNinty(triangle.getB()) ||
    math.isNinty(triangle.getC());
}

bool Classifier::hasObtuseAngle(Triangle triangle)
{
  return math.greaterThanNinty(triangle.getA()) ||
    math.greaterThanNinty(triangle.getB()) ||
    math.greaterThanNinty(triangle.getC());
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
      if ( validator.hasLengths(triangle) )
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
