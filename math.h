/*
  Copyright 2017, Sjors van Gelderen

  TODO: 
  - Use templates for generic vectors
  - Override operators for the vectors
  
*/

#ifndef MATH_H
#define MATH_H

class Vector2
{
public:
    Vector2(float _x, float _y);
    float GetX();
    float GetY();
    void SetX(float _x);
    void SetY(float _y);

private:
    float x;
    float y;
};

#endif
