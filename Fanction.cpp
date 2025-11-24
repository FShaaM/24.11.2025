#include "Fanction.h"

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

Planar* most_left(Planar** pls, size_t k)
{
	return nullptr;
}


Planar* make(size_t id)
{
	Planar* r = nullptr;
	switch (id)
	{
	case 0:
		r = new Point(0, 0);

	default:
		throw std::logic_error("bad id");
	}

	return r;
}
