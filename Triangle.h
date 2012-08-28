#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "FloatMath.h"
#include <math.h>
#include <float.h>

namespace Triangles 
{

  class Triangle 
  {
  public:
  Triangle(float l0, float l1, float l2, float a0, float a1, float a2) 
    : length0(l0), 
      length1(l1), 
      length2(l2),
      angle0(a0), 
      angle1(a1), 
      angle2(a2)  
    {
    };

    ~Triangle() {};
    
    float getLength0() { return length0; }
    float getLength1() { return length1; }
    float getLength2() { return length2; }
    float getAngle0() { return angle0; }
    float getAngle1() { return angle1; }
    float getAngle2() { return angle2; }
    bool hasLengths() 
    {
      FloatMath math = FloatMath();
      return !( math.isZero(length0) &&
		math.isZero(length1) &&
		math.isZero(length2) );
    }

  private:
    float length0;
    float length1;
    float length2;
    float angle0;
    float angle1;
    float angle2;
  };
}

#endif
