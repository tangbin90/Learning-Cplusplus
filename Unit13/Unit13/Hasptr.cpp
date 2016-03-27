#include "stdafx.h"
#include "Hasptr.h"
#include <iostream>

inline void
swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
	swap(lhs.i, rhs.i);   // swap the int members
	swap(lhs.use, rhs.use);
	std::cout << "swapping!\n";

}

HasPtr& HasPtr::operator = (HasPtr&& rhs) _NOEXCEPT
{
	if (this != &rhs)
	{
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
		ps = rhs.ps;
		i = rhs.i;
		use = rhs.use;
	}
	return *this;
}
