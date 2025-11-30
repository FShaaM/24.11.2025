#include "Fanction.h"
#include "Vector.h"
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
		return pls;

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

	throw std::logic_error("bad cmd");
}
