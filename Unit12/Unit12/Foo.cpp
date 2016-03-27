#include "Foo.h"
#include <algorithm>

Foo Foo::sorted() &&
{
	sort(data.begin(), data.end());
	std::cout << "&&" << std::endl;
	return *this;
}