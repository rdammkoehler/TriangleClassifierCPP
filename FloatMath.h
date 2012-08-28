#ifndef FLOAT_MATH_H
#define FLOAT_MATH_H

namespace Triangles
{

  class FloatMath
  {
  public:
    FloatMath() {};
    ~FloatMath() {};
    bool isZero(float);
    bool equal(float, float);
    bool isNegative(float);
    bool isOneEighty(float);
    bool isNinty(float);
    bool greaterThanNinty(float);
    bool lessThanNinty(float);
  };
}

#endif
