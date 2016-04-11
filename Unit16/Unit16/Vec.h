#ifndef STRVEC_H
#define STRVEC_H
#include <string>
#include <memory>
#include <algorithm>

template <typename T>
class Vec
{
public:
	typedef T valuetype;
	Vec() :elements(nullptr), first_free(nullptr), cap(nullptr){}
	Vec(const Vec&);
	Vec(std::initializer_list<valuetype>);
	Vec<valuetype>& operator=(const Vec<valuetype>&);
	~Vec();
	void push_back(const valuetype&);
	size_t size() const{ return cap - elements; };
	size_t capacity() const{ return cap - elements; }
	valuetype* begin() const { return elements; }
	valuetype* end() const { return first_free; }
	void reserve(size_t size);
	size_t capacity();
	size_t size();	
	valuetype& at(size_t pos);
	void resize(size_t size);
	void resize(size_t size, valuetype& T);
private:
	void chk_n_alloc()
	{
		if (size() == capacity()) reallocate();
	}
	std::pair<valuetype*, valuetype*> alloc_n_copy(const valuetype*, const valuetype*);
	void free();
	void reallocate();
private:
	std::allocator<valuetype> alloc;
	valuetype* elements;
	valuetype* first_free;
	valuetype* cap;
};

template <typename T> void Vec<T>::push_back(const T& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

template <typename T> std::pair<T*, T*>
Vec<T>::alloc_n_copy(const T *b, const T *e)
{
	auto data = alloc.allocate(e - b);
	return{ data, uninitialized_copy(b, e, data) };
}

template <typename T> void Vec<T>::free()
{
	if (elements)
	{
		for_each(elements, first_free, [this](T& str){alloc.destroy(&str); });
		alloc.deallocate(elements, cap - elements);
	}
}

template <typename T> Vec<T>::Vec(const Vec<T> &s)
{
	using namespace std;
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template <typename T> Vec<T>::~Vec()
{
	free();
}

template <typename T> Vec<T>& Vec<T>::operator=(const Vec<T> &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template <typename T> void Vec<T>::reallocate()
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

template <typename T> void Vec<T>::reserve(size_t size)
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

template <typename T> size_t Vec<T>::capacity()
{
	return cap - elements;
}

template <typename T> size_t Vec<T>::size()
{
	return first_free - elements;
}

template <typename T> void Vec<T>::resize(size_t size)
{
	if (size > this->size())
	{
		while (size > capacity())
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
			for (int i = 0; i != this->size() - size; i++)
				alloc.destroy(--first_free);
		}
	}
	else
		return;
}

template <typename T> void Vec<T>::resize(size_t size, T& T)
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

template <typename T> Vec<T>::Vec(std::initializer_list<T> li)
{
	auto data = alloc_n_copy(li.begin(), li.end());
	elements = data.first;
	first_free = cap = data.second;
}

template <typename T> T& Vec<T>::at(size_t pos)
{
	return *(elements + pos);
}
#endif