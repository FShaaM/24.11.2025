#include "Rhomb.h"
#include <cmath>

Rhomb::Rhomb() :
  Planar(),
  center(0, 0),
  diagonal_G(0),
  diagonal_V(0)
{}

Rhomb::Rhomb(Point center, int diag1, int diag2) :
  Planar(),
  center(center),
  diagonal_G(diag1),
  diagonal_V(diag2)
{}

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
    return (diagonal_V * diagonal_V + diagonal_G * diagonal_G) / 4;
}

double Rhomb::area() const
{
  return (diagonal_V * diagonal_G) / 2.0;
}

Frame Rhomb::frame() const
{
  int half_G = diagonal_G / 2;
  int half_V = diagonal_V / 2;

  int minX = center.x() - half_G;
  int maxX = center.x() + half_G;
  int minY = center.y() - half_V;
  int maxY = center.y() + half_V;

  const int padding = 1;
  return Frame(minX - 1, minY - 1, maxX + 1, maxY + 1);
}
