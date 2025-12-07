#include "Point.h"

Point::Point() :
	Planar(),
	data{0, 0}
{}

Point::Point(int xx, int yy) :
	Planar(),
	data{ xx, yy }
{}

int Point::x() const
{
	return data[0];
}

int Point::y() const
{
	return data[1];
}

int Point::abc_sqr() const
{
	return x() * x() + y() * y();
}

double Point::area() const
{
  return 0.0;
}
Frame Point::frame() const
{
  int a = x();
  int b = y();

  return Frame(a - 1, b - 1, a + 1, b + 1);
}
