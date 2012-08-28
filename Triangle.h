#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "FloatMath.h"
#include <math.h>
#include <float.h>

namespace Triangles 
{

  //a, b, c are lengths, A, B, C are angles opposite those sides
  class Triangle 
  {
  public:
  Triangle(float a, float b, float c, float A, float B, float C) 
    : a(a), 
      b(b), 
      c(c),
      A(A), 
      B(B), 
      C(C)  
    {
    };

    ~Triangle() {};
    
    float geta() { return a; }
    float getb() { return b; }
    float getc() { return c; }
    float getA() { return A; }
    float getB() { return B; }
    float getC() { return C; }

  private:
    float a;
    float b;
    float c;
    float A;
    float B;
    float C;
  };
}

#endif
