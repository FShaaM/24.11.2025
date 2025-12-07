#include"Vector.h"

int Vector::x() const
{
	return dataP[1].x() - dataP[0].x();
}

int Vector::y() const
{
	return dataP[1].y() - dataP[0].y();
}

int Vector::abc_sqr() const
{
	int m = dataP[1].x() - dataP[0].x();
	int n = dataP[1].y() - dataP[0].y();

	return m * m + n * n;
}

Vector::Vector(Point beginning, Point end) :
  Planar()
{
	dataP[0] = beginning;
	dataP[1] = end;
}

double Vector::area() const
{
  return 0.0;
}

Frame Vector::frame() const
{
   Point A = dataP[0];
   Point B = dataP[1];

  int minX = (A.x() < B.x()) ? A.x() : B.x();
  int maxX = (A.x() > B.x()) ? A.x() : B.x();
  int minY = (A.y() < B.y()) ? A.y() : B.y();
  int maxY = (A.y() > B.y()) ? A.y() : B.y();

  const int padding = 1;
  return Frame(minX - 1, minY - 1, maxX + 1, maxY + 1);
}
