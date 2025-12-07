#include "Fanction.h"
#include "Vector.h"
#include "Rhomb.h"
#include <stdexcept>

void free_planars(Planar** pls, size_t k)
{
	for (size_t i = 0; i < k; ++i)
		delete pls[i];
}

void draw(Planar* pl)
{
	std::cout << pl->x() << " ";
	std::cout << pl->y() << "\n";
}

Planar** most_left(Planar** pls, size_t k)
{
	if (!k)
	{
		return pls;
  }

	Planar** res = pls;
  Planar** current = pls;

	while (--k)
	{
		int nextX = (*(++current)) -> x();
		int currX = (*res) -> x();

		if (nextX < currX)
			res = current;
	}

	return res;
}


Planar* make(size_t id)
{
	Planar* r = nullptr;

	switch (id)
	{
    case 0:
	  	r = new Point(0, 0);
	  	break;

	  case 1:
        r = new Vector(Point(0, 0), Point(1, 1));
        break;

    case 2:
        r = new Rhomb(Point(0, 0), 4, 4);
        break;

  	default:
	  	throw std::logic_error("bad id");
	}

	return r;
}

Planar* make(std::istream& is)
{
    char cmd[2] = {};
    int data[2] = {};

    is >> cmd[0] >> cmd[1];

    if (!is)
        return nullptr;

    if (cmd[0] == 'P' && cmd[1] == 'T')
    {
        if (is >> data[0] >> data[1])
            return new Point(data[0], data[1]);
    }
    else if (cmd[0] == 'V' && cmd[1] == 'T')
    {
        int x1, y1, x2, y2;

        if (is >> x1 >> y1 >> x2 >> y2)
            return new Vector(Point(x1, y1), Point(x2, y2));
    }
    else if (cmd[0] == 'R' && cmd[1] == 'H')
    {
        int x, y, d1, d2;

        if (is >> x >> y >> d1 >> d2)
            return new Rhomb(Point(x, y), d1, d2);
    }

    throw std::logic_error("bad cmd");
}

Planar** max_area(Planar** pls, size_t k)
{
  if (!k)
  {
    return nullptr;
  }

  Planar** m_a = pls;

  for (size_t i = 1; i < k; ++i)
  {
    if ((*m_a)->area() < pls[i]->area())
    {
      m_a = &pls[i];
    }
  }

  return m_a;
}

Planar** max_frame_intersects(Planar** pls, size_t k)
{
  if (k < 2)
  {
    return nullptr;
  }

  Planar** result = new Planar*[2];
  result[0] = pls[0];
  result[1] = pls[1];

  Frame first_frame = pls[0]->frame();
  int max_intersection = first_frame.intersection_area(pls[1]->frame());

  for (size_t i = 0; i < k - 1; ++i)
  {
    Frame frame_i = pls[i]->frame();

    for (size_t j = i + 1; j < k; ++j)
    {
      Frame frame_j = pls[j]->frame();
      int current_intersection = frame_i.intersection_area(frame_j);

      if (current_intersection > max_intersection)
      {
        max_intersection = current_intersection;
        result[0] = pls[i];
        result[1] = pls[j];
      }
    }
  }

  return result;
}
