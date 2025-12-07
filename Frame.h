#ifndef FRAME_H

#define FRAME_H

struct Frame
{
  int minX, minY;
  int maxX, maxY;

  Frame();
  Frame(int minX, int minY, int maxX, int maxY);
  int intersection_area(const Frame& other) const;
  Frame& operator=(const Frame& other);
};

#endif
