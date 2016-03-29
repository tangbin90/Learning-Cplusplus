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
	friend class StrBlobPtr;
public:
	using size_type = vector<string>::size_type;
	StrBlobPtr begin();// { //return StrBlobPtr(*this);
	//}
	StrBlobPtr end();
	//{
		//auto ret = StrBlobPtr(*this, data->size());
		//return ret;
	//}
	typedef vector<string>::size_type size_type;
	StrBlob() :data(make_shared<vector<string>>()){};
	StrBlob(initializer_list<string> i1) :data(make_shared<vector<string>>(i1)){};
	size_type size() const{ return data->size(); }
	bool empty(){ return data->empty(); }
	void push_back(string str){ data->push_back(str); }
	void push_back(string&& str){ data->push_back(std::move(str)); }
	void pop_back();
	string& front() const;
	string& back() const;

	shared_ptr<vector<string>> data;
	void check(size_type i, const std::string &msg) const;
};

bool operator==(const StrBlob& str1, const StrBlob& str2);
bool operator!=(const StrBlob &lhs, const StrBlob &rhs);

class StrBlobPtr
{
public:
	StrBlobPtr() :curr(0){}
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz){}
	string& deref() const;
	StrBlobPtr& incr();
	bool operator!=(const StrBlobPtr& strptr);

private:
	shared_ptr<vector<string>> check(size_t, const string&) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};

class ConststrBlobPtr
{
public:
	using size_t = vector<string>::size_type;
	ConststrBlobPtr() :curr(0){}
	ConststrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz){}
	string& deref() const
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
	bool operator!=(const StrBlobPtr& strptr);


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

#endif