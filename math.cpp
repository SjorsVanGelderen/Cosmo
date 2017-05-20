#include "math.h"

Vector2::Vector2(float _x, float _y)
{
    x = _x;
    y = _y;
}

/*
  Vector2::add(Vector2 _left, Vector2 _right)
  {
  return new Vector2(_left.GetX() + _right.GetX(),
  _left.GetY() + _right.GetY());
  }

  Vector2::sub(Vector2 _left, Vector2 _right)
  {
  return new Vector2(_left.GetX() - _right.GetX(),
  _left.GetY() - _right.GetY());
  }

  Vector2::div(Vector2 _vec, float _scalar)
  {
  return new Vector2(_vec.GetX() / _scalar,
  _vec.GetY() / _scalar);
  }

  float Vector2::mag(Vector2 _vec)
  {
  return sqrt(pow(_vec.GetX(), 2) + pow(_vec.GetY(), 2));
  }

  Vector2::norm(Vector2 _vec)
  {
  _vec / mag(_vec);
  }
*/

float Vector2::GetX()
{
    return x;
}

float Vector2::GetY()
{
    return y;
}

void Vector2::SetX(float _x)
{
    x = _x;
}

void Vector2::SetY(float _y)
{
    y = _y;
}
