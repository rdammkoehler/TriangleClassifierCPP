#include "FloatMath.h"
#include <math.h>
#include <float.h>

using namespace Triangles;

bool FloatMath::equal(float a, float b) 
{
  return fabs( a - b ) < FLT_EPSILON;
}

bool FloatMath::isZero(float f) 
{
  return equal(0.0f, f);
}

bool FloatMath::isNegative(float d)
{
  return 0.0f > d;
}

bool FloatMath::isOneEighty(float f) 
{
  return equal(180.0f, f);
}

bool FloatMath::isNinty(float angle)
{
  return equal(90.0f, angle);
}

bool FloatMath::greaterThanNinty(float angle)
{
  return angle > 90.0f;
}

bool FloatMath::lessThanNinty(float angle) 
{
  return angle < 90.0f;
}

