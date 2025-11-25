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

Vector::Vector(Point beginning, Point end)
{
	dataP[0] = beginning;
	dataP[1] = end;
}
