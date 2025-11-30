#include <iostream>
#include "Planar.h"
#include "Point.h"
#include "Fanction.h"

int main()
{
	

	size_t s = 0;
	size_t capusity = 20;

	Planar** pls = new Planar * [capusity];

	while (std::cin)
	{
		Planar* pl = nullptr;

		try
		{
			pl = make(std::cin);

			if (s == capusity)
			{
				Planar** epls = new Planar* [capusity * 12];

				for (size_t i = 0; i < s; ++i)
				{
					epls[i] = pls[i];
				}

				delete[] pls;
				pls = epls;
				capusity *= 1.2;
			}

			pls[s++] = pl;
		}
		catch (...)
		{
			delete pl;
			free_planars(pls, s);
			delete[] pls;
			return 1;
		}

		if (!std::cin.eof() && !std::cin)
		{
			free_planars(pls, s);
			delete[] pls;
			return 1;
		}
	}

	Planar** ml = most_left(pls, s);

	if (ml == pls + s)
	{
		std::cout << "Net fuond";
		free_planars(pls, s);
		delete[] pls;
		return 0;
	}

	std::cout << "New  most left" << "\n";
	draw(*ml);
	free_planars(pls, s);
	delete[] pls;
}
