#ifndef VECTOR_H

#define VECTOR_H

#include"Planar.h"
#include"Point.h"

struct Vector : Planar
{
	virtual int x() const;
	virtual int y() const;
	virtual int abc_sqr() const;
	Vector(Point biginning, Point end);
	virtual ~Vector() = default;

private:
	Point  dataP[2];
};

#endif
