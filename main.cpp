#include <iostream>

struct Planar
{
	virtual int x() const;
	virtual int y() const;
	virtual int abc_sqr() const;
	virtual ~Planar() = default;
};

Planar* make(std::istream& is);
Planar* most_left(Planar** pls, size_t k);
Planar* make(size_t pl);
void draw(Planar* pl);
void free_planars(Planar** pls, size_t k);

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
	
