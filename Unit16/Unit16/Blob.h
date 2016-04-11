#ifndef Blob_h
#define Blob_h
#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <string>
#include <memory>
#include "BlobPtr.h"

using namespace std;

template <typename> class Blob;
template <typename> class BlobPtr;

template <typename T> bool operator==(const Blob<T>& str1, const Blob<T>& str2);
template <typename T> bool operator<(const Blob<T>& str1, const Blob<T>& str2);
template <typename T> bool operator!=(const Blob<T>& str1, const Blob<T>& str2);

template <typename T> 
class Blob
{
	friend bool operator==<T>(const Blob<T>& str1, const Blob<T>& str2);
	friend bool operator!=<T>(const Blob<T> &lhs, const Blob<T> &rhs);
	friend bool operator< <T>(const Blob<T> &lhs, const Blob<T> &rhs);

	friend class BlobPtr<T>;
public:

	typedef typename std::vector<T>::size_type size_type;
	template <typename It> Blob(It b, It e);
	Blob() :data(make_shared<vector<T>>()){};
	Blob(initializer_list<T> i1) :data(make_shared<vector<T>>(i1)){};

	size_type size() const{ return data->size(); }
	bool empty(){ return data->empty(); }
	void push_back(T str){ data->push_back(str); }
	void push_back(T&& str){ data->push_back(std::move(str)); }
	void pop_back();
	T& operator[](size_t n);
	const T& operator[](size_t n) const;
	T& front() const;
	T& back() const;
private:
	shared_ptr<vector<T>> data;
	void check(size_type i, const T &msg) const;
};

template <typename T> void Blob<T>::check(size_type i, const T &msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

template <typename T> void Blob<T>::pop_back()
{
	check(0, "popback on empty StrBlob");
	data->pop_back();
}

template <typename T> T& Blob<T>::front() const
{
	check(0, "front on empty Strblob");
	return data->front();
}

template <typename T> T& Blob<T>::back() const
{
	check(0, "back on emptu Strblob");
	return data->back();
}

template <typename T> bool operator==(const Blob<T>& str1, const Blob<T>& str2)
{
	return *str1.data == *str2.data;
}

template <typename T> bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs)
{
	return !(lhs == rhs);
}

template <typename T> bool operator<(const Blob<T> &lhs, const Blob<T> &rhs)
{
	return *lhs.data < *rhs.data;
}

template <typename T> T& Blob<T>::operator[](size_t n)
{
	check(n, "out of range");
	return (*data)[n];
}

template <typename T> const T& Blob<T>::operator[](size_t n) const
{
	check(n, "out of range");
	return (*data)[n];
}

template <typename T> template <typename It> Blob<T>::Blob(It b, It e) :data(std::make_shared<std::vector<T>>(b,e))
{}

#endif