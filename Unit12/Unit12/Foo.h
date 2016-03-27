#ifndef FOO_H
#define FOO_H
#include <vector>
#include <iostream>

using namespace std;

class Foo
{
public:
	Foo sorted() &&;
	Foo sorted() const &;
private:
	vector<int> data;
};

Foo Foo::sorted() const & {
	//    Foo ret(*this);
	//    sort(ret.data.begin(), ret.data.end());
	//    return ret;

	std::cout << "const &" << std::endl; // debug

	//    Foo ret(*this);
	//    ret.sorted();     // Exercise 13.56
	//    return ret;

	return Foo(*this).sorted(); // Exercise 13.57
}

#endif