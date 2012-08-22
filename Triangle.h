#ifndef TRIANGLE_H
#define TRIANGLE_H

namespace Triangles 
{

  class Triangle 
  {
  public:
  Triangle(int l0, int l1, int l2) 
    : length0(l0), 
      length1(l1), 
      length2(l2),
      angle0(0.0f),
      angle1(0.0f),
      angle2(0.0f) 
    {
    };

  Triangle(float a0, float a1, float a2) 
    : length0(0),
      length1(0),
      length2(0),
      angle0(a0), 
      angle1(a1), 
      angle2(a2) 
    {
    };
    
    ~Triangle() {};
    
    int getLength0() { return length0; }
    int getLength1() { return length1; }
    int getLength2() { return length2; }
    float getAngle0() { return angle0; }
    float getAngle1() { return angle1; }
    float getAngle2() { return angle2; }

  private:
    int length0;
    int length1;
    int length2;
    float angle0;
    float angle1;
    float angle2;
  };
}

#endif
