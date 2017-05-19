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
  float GetX();
  float GetY();

 private:
  float x;
  float y;
};

#endif
