#include "stdafx.h"
#include "StrVec.h"

void StrVec::push_back(const std::string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e - b);
	return{ data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	if (elements)
	{
		for (auto p = first_free; p != elements;)
		{
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
		first_free = elements;
	}
}

StrVec::StrVec(const StrVec &s)
{
	using namespace std;
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
void StrVec::push_back(std::string &&s)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}

StrVec::~StrVec()
{
	free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}   

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++, std::move(*elem++));
	}
	free();

	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::reserve(size_t size)
{
	
	if (size > capacity())
	{
		auto newdata = alloc.allocate(size);
		auto dest = newdata;
		auto elem = elements;
		for (size_t i = 0; i != size; ++i)
		{
			alloc.construct(newdata++, std::move(*elem++));
		}
		free();

		elements = newdata;
		first_free = dest;
		cap = elements + size;
	}
	return;
}

size_t StrVec::capacity()
{
	return cap - elements;
}

size_t StrVec::size()
{
	return first_free - elements;
}

void StrVec::resize(size_t size)
{
	if (size > this->size())
	{
		while(size > capacity())
		{
			reallocate();
		}
		for (int i = 0; i != size - this->size(); i++)
			alloc.construct(first_free++, "");
	}
	else if (size < this->size())
	{
		for (int i = 0; i != this->size() - size; i++)
		{
			for (int i = 0; i != this->size()-size; i++)
				alloc.destroy(--first_free);
		}
	}
	else
		return;
}

void StrVec::resize(size_t size, std::string& T)
{
	if (size > this->size())
	{
		while (size > capacity())
		{
			reallocate();
		}
		for (int i = 0; i != size - this->size(); i++)
			alloc.construct(first_free++, T);
	}
	else if (size < this->size())
	{
		for (int i = 0; i != this->size() - size; i++)
		{
			for (int i = 0; i != this->size() - size; i++)
				alloc.destroy(--first_free);
		}
	}
	else
		return;
}

StrVec::StrVec(StrVec &&p) _NOEXCEPT:elements(p.elements), first_free(p.first_free), cap(p.cap)
{
	p.elements = nullptr;
	p.first_free = nullptr;
	p.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) _NOEXCEPT
{
	if (this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

StrVec::StrVec(std::initializer_list<std::string> li)
{
	auto data = alloc_n_copy(li.begin(), li.end());
	elements = data.first;
	first_free = cap = data.second;
}

bool operator==(const StrVec& str1, const StrVec& str2)
{
	if (str1.size() != str2.size())
		return false;
	std::string* c = str1.begin();
	std::string* s = str2.begin();
	while (c != str1.end())
	{
		if (*c++ != *s++)
		{
			return false;
		}
	}
	return true;
}

bool operator!=(const StrVec& str1, const StrVec& str2)
{
	return !(str1 == str2);
}

StrVec& StrVec::operator=(std::initializer_list<std::string> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

std::string& StrVec::operator[](std::size_t n)
{
	if (n >= size())
	{
		throw std::out_of_range("Out of range");
	}
	return *(elements + n);
}

const std::string& StrVec::operator[](std::size_t n) const 
{
	if (n >= size())
	{
		throw std::out_of_range("Out of range");
	}
	return *(elements + n);
}
