#ifndef RHOMB_H

#define RHOMB_H

#include "Planar.h"
#include "Point.h"

struct Rhomb : Planar
{
  virtual int x() const;
  virtual int y() const;
  virtual int abc_sqr() const;

  Rhomb();
  Rhomb(Point center, int diag1, int diag2);
  Rhomb(Point p1, Point p2, Point p3, Point p4);
}

#endif
