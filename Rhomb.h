#ifndef RHOMB_H

#define RHOMB_H

#include "Planar.h"
#include "Point.h"
#include "Frame.h"

struct Rhomb : Planar
{
  Point center;
  int diagonal_G;
  int diagonal_V;

  virtual int x() const;
  virtual int y() const;
  virtual int abc_sqr() const;
  virtual double area() const;
  virtual Frame frame() const;

  Rhomb();
  Rhomb(Point center, int diagG, int diagV);
};

#endif
