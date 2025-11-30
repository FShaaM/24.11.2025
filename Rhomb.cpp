#include "Rhomb.h"
#include <cmath>

Rhomb::Rhomb() :
  center(0, 0),
  diagonal_G(0),
  diagonal_V(0)
{}

Rhomb::Rhomb(Point center, int diag1, int diag2) :
    center(center),
    diagonal_G(diag1),
    diagonal_V(diag2)
{}

Rhomb::Rhomb(Point A, Point B, Point C, Point D)
{
  int center_X = (p1.x() + p2.x() + p3.x() + p4.x()) / 4;
  int center_Y = (p1.y() + p2.y() + p3.y() + p4.y()) / 4;

  center = Point(center_X, center_Y);

  if (A.x() - C.x())
  {
    diagonal_G = std::abs(B.x() - D.x());
    diagonal_V = std::abs(A.x() - C.x());
  }
  else
  {
    diagonal_V = std::abs(B.x() - D.x());
    diagonal_G = std::abs(A.x() - C.x());
  }
}

int Rhomb::x() const
{
    return center.x();
}

int Rhomb::y() const
{
    return center.y();
}

int Rhomb::abc_sqr() const
{
    return 2 * std::sqrt(diagonal_V * diagonal_V + diagonal_G * diagonal_G);
}
