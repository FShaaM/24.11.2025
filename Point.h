#ifndef POINT_H

#define POINT_H

#include "Planar.h"
#include "Frame.h"

struct Point : Planar
{
	virtual int x() const;
	virtual int y() const;
	virtual int abc_sqr() const;
	virtual double area() const;
	virtual Frame frame() const;
	Point();
	Point(int xx, int yy);
	virtual ~Point() = default;

private:
	int  data[2];
};

#endif
