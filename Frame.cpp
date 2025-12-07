#include "Frame.h"

Frame::Frame() :
  minX(0),
  minY(0),
  maxX(0),
  maxY(0)
{}

Frame::Frame(int minX, int minY, int maxX, int maxY) :
  minX(minX),
  minY(minY),
  maxX(maxX),
  maxY(maxY)
{}

Frame& Frame::operator=(const Frame& other)
{
  if (this == &other)
  {
    return *this;
  }

  minX = other.minX;
  minY = other.minY;
  maxX = other.maxX;
  maxY = other.maxY;

  return *this;
}

int Frame::intersection_area(const Frame& other) const
{
  int overlap_minX = (minX > other.minX) ? minX : other.minX;
  int overlap_maxX = (maxX < other.maxX) ? maxX : other.maxX;
  int overlap_minY = (minY > other.minY) ? minY : other.minY;
  int overlap_maxY = (maxY < other.maxY) ? maxY : other.maxY;

  if (overlap_minX >= overlap_maxX || overlap_minY >= overlap_maxY)
  {
    return 0;
  }

  int overlap_width = overlap_maxX - overlap_minX;
  int overlap_height = overlap_maxY - overlap_minY;

  return overlap_width * overlap_height;
}
