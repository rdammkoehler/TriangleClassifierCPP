#include "Classifier.h"

Triangles::Classifier::Type Triangles::Classifier::classify(Triangle triangle)
{
  Triangles::Classifier::Type type = invalid;
  if (triangle.getLength0() == triangle.getLength1() &&
      triangle.getLength0() == triangle.getLength2())
    {
      type = equilateral;
    } else if (triangle.getLength0() == triangle.getLength1() ||
	       triangle.getLength0() == triangle.getLength2() ||
	       triangle.getLength1() == triangle.getLength2())
    {
      type = isosceles;
    } else {
    type = scalene;
  }
  return type;
}
