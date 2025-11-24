#include <iostream>
#include "Planar.h"
#include "Point.h"
#include "Fanction.h"


int main()
{
	Planar* pls[10] = {};
	size_t k = 0;

	//pls[k++] = make(std::cin);

	Planar* left = most_left(pls, k);

	for (size_t i = 0; i < 10; ++i)
	{
		try
		{
			pls[k] = make(i % 2);
		}
		catch (...)
		{
			free_planars(pls, k);
			return 2;
		}
		k++;
	}

	draw(most_left(pls,k));
	free_planars(pls, k);
}
