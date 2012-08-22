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
      length2(l2) 
    {
    };

  Triangle(float a0, float a1, float a2) 
    : angle0(a0), 
      angle1(a1), 
      angle2(a2) 
    {
    };
    
    ~Triangle() {};
    
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
