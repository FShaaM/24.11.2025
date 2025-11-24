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

int main()
{
	Planar* pls[10] = {};
	size_t k = 0;

	//pls[k++] = make(std::cin);

	Planar* left = most_left(pls, k);

	//drow(left);

	// free_planars(pls, k);
}
