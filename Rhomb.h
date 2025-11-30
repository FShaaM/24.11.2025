#ifndef RHOMB_H

#define RHOMB_H

#include "Planar.h"
#include "Point.h"

struct Rhomb : Planar
{
  Point center;
  int diagonal_G;
  int diagonal_V;

  virtual int x() const;
  virtual int y() const;
  virtual int abc_sqr() const;

  Rhomb();
  Rhomb(Point A, Point B, Point C, Point D);
  Rhomb(Point center, int diagG, int diagV);
};

#endif
