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
public:
	using size_type = vector<string>::size_type;
	friend class StrBlobPtr;
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
	StrBlob(const StrBlob& strblob)
	{
		data = strblob.data;
	}

	StrBlob& operator=(StrBlob& str)
	{
		data = str.data;

	}
	size_type size() const{ return data->size(); }
	bool empty(){ return data->empty(); }
	void push_back(string str){ data->push_back(str); }
	void pop_back();
	string& front() const;
	string& back() const;

	shared_ptr<vector<string>> data;
	void check(size_type i, const std::string &msg) const;
};
/*
class StrBlob {
public:
	using size_type = vector<string>::size_type;
	friend class StrBlobPtr;

	StrBlobPtr begin();
	StrBlobPtr end();

	StrBlob() : data(std::make_shared<vector<string>>()) {}
	StrBlob(std::initializer_list<string> il)
		: data(std::make_shared<vector<string>>(il))
	{
	}

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const string& t) { data->push_back(t); }
	void pop_back()
	{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}

	std::string& front()
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}

	std::string& back()
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}

	const std::string& front() const
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}
	const std::string& back() const
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}

private:
	void check(size_type i, const string& msg) const
	{
		if (i >= data->size()) throw std::out_of_range(msg);
	}

private:
	std::shared_ptr<vector<string>> data;
};
*/

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