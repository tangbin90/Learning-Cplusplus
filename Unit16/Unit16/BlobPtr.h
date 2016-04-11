#ifndef BLOBPTR_H
#define BLOBPTR_H

#include "Blob.h"
#include <memory>
#include <vector>

template <typename> class BlobPtr;
template <typename> class Blob;

template <typename T>
bool operator ==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template <typename T>
bool operator < (const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template<typename T>
class BlobPtr
{
	friend bool operator==<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
	friend bool operator< <T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

public:
	typedef T valuetype;
	BlobPtr() :curr(0){}
	BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz){}
	valuetype& deref() const;
	BlobPtr& incr();
	bool operator!=(const BlobPtr& strptr);
	valuetype& operator[](std::size_t n);

	BlobPtr<T>& operator++();
	BlobPtr<T>& operator--();
	BlobPtr<T> operator++(int);
	BlobPtr<T> operator--(int);

	valuetype & operator*() const;
	valuetype* operator->() const;
//private:
//	shared_ptr< vector<T> > check(std::size_t, const string&) const;
//	weak_ptr< vector<T> > wptr;
//	size_t curr;

//public:
//	BlobPtr() : curr(0) { }
//	BlobPtr(Blob<T>& a, std::size_t sz = 0) :
//		wptr(a.data), curr(sz) { }
//
//	T& operator*() const
//	{
//		auto p = check(curr, "dereference past end");
//		return (*p)[curr];
//	}
//
//	// prefix
//	BlobPtr& operator++();
//	BlobPtr& operator--();
//
//	// postfix
//	BlobPtr operator ++(int);
//	BlobPtr operator --(int);

private:
	std::shared_ptr< std::vector<T> > check(std::size_t, const std::string&) const;
	std::weak_ptr< std::vector<T> > wptr;
	std::size_t curr;

};


template<typename T> std::shared_ptr<std::vector<T>>  BlobPtr<T>::check(std::size_t i, const std::string &msg)const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");

	if (i >= ret->size())
	{
		throw out_of_range(msg);
	}
	return ret;
}

template<typename T> T& BlobPtr<T>::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

template<typename T> BlobPtr<T>& BlobPtr<T>::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

template<typename T> bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return lhs.curr == rhs.curr;
}

template<typename T> bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return !(lhs == rhs);
}

template<typename T> bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	if (lhs.wptr.lock() != rhs.wptr.lock()) {
		throw runtime_error("ptrs to different Blobs!");
	}
	return lhs.curr < rhs.curr;
}

template<typename T> T& BlobPtr<T>::operator[](size_t n)
{
	auto p = check(curr + n, "dereference past end");
	return (*p)[n + curr];
}

template<typename T> BlobPtr<T>& BlobPtr<T>::operator++()//Ç°ÖÃµÝÔö
{
	check(curr, "increment past end of strBlobPtr");
	++curr;
	return *this;
}

template<typename T> BlobPtr<T>& BlobPtr<T>::operator--()
{
	--curr;
	check(curr, "decrement past begin of strBlobPtr");
	return *this;
}

template<typename T> BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;
	++*this;
	return ret;
}

template<typename T> BlobPtr<T> BlobPtr<T>::operator--(int)
{
	BlobPtr ret = *this;
	--*this;
	return ret;
}

template<typename T> T& BlobPtr<T>::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

template<typename T> T* BlobPtr<T>::operator->() const
{
	return &this->operator*();
}


#endif