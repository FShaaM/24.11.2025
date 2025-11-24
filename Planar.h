#ifndef PLANAR_H

#define PLANAR_H

struct Planar
{
	virtual int x() const = 0;
	virtual int y() const = 0;
	virtual int abc_sqr() const = 0;
	virtual ~Planar() = default;
};

#endif
