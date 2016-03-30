#ifndef Blob_h
#define Blob_h
#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class StrBlob
{
	friend bool operator==(const StrBlob& str1, const StrBlob& str2);
	friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);

	friend class StrBlobPtr;
	friend class ConststrBlobPtr;
public:
	using size_type = vector<string>::size_type;
	ConststrBlobPtr begin() const;
	ConststrBlobPtr end() const;

	typedef vector<string>::size_type size_type;
	StrBlob() :data(make_shared<vector<string>>()){};
	StrBlob(initializer_list<string> i1) :data(make_shared<vector<string>>(i1)){};
	size_type size() const{ return data->size(); }
	bool empty(){ return data->empty(); }
	void push_back(string str){ data->push_back(str); }
	void push_back(string&& str){ data->push_back(std::move(str)); }
	void pop_back();
	string& operator[](std::size_t n);
	const string& operator[](std::size_t n) const;
	string& front() const;
	string& back() const;
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const std::string &msg) const;
};

bool operator==(const StrBlob& str1, const StrBlob& str2);
bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
bool operator<(const StrBlob &lhs, const StrBlob &rhs);

class StrBlobPtr
{
	friend bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
	friend bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
	friend bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs);

public:
	StrBlobPtr() :curr(0){}
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz){}
	string& deref() const;
	StrBlobPtr& incr();
	bool operator!=(const StrBlobPtr& strptr);
	string& operator[](std::size_t n);
	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr& operator++(int);
	StrBlobPtr& operator--(int);
	const string& operator[](std::size_t n) const;

private:
	shared_ptr<vector<string>> check(size_t, const string&) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};
bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs);

class ConststrBlobPtr
{
	friend bool operator==(const ConststrBlobPtr& lhs, const ConststrBlobPtr& rhs);
	friend bool operator!=(const ConststrBlobPtr& lhs, const ConststrBlobPtr& rhs);
	friend bool operator<(const ConststrBlobPtr& lhs, const ConststrBlobPtr& rhs);
public:
	using size_t = vector<string>::size_type;
	ConststrBlobPtr() :curr(0){}
	ConststrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz){}
	const string& deref() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	ConststrBlobPtr& incr()
	{
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}
private:
	shared_ptr<vector<string>> check(size_t i, const string& msg) const
	{
		{
			auto ret = wptr.lock();
			if (!ret) throw std::runtime_error("unbound StrBlobPtr");
			if (i >= ret->size()) throw std::out_of_range(msg);
			return ret;
		}
	}
	weak_ptr<vector<string>> wptr;
	size_t curr;
};
bool operator==(const ConststrBlobPtr& lhs, const ConststrBlobPtr& rhs);
bool operator!=(const ConststrBlobPtr& lhs, const ConststrBlobPtr& rhs);
bool operator<(const ConststrBlobPtr& lhs, const ConststrBlobPtr& rhs);
#endif