#ifndef FANCTION_H

#define FANCTION_H

#include "Planar.h"
#include "Point.h"
#include <iostream>

Planar* make(std::istream& is);
Planar** most_left(Planar** pls, size_t k);
Planar* make(size_t pl);
void draw(Planar* pl);
void free_planars(Planar** pls, size_t k);
Planar** max_area(Planar** pls, size_t k);
Planar** max_frame_intersects(Planar ** pls, size_t k);

#endif

