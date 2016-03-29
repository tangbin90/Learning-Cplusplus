#include "stdafx.h"
#include "Blob.h"
ConststrBlobPtr StrBlob::begin() const
{
	return ConststrBlobPtr(*this);
}
ConststrBlobPtr StrBlob::end() const
{
	return ConststrBlobPtr(*this, data->size());
}
void StrBlob::check(size_type i, const std::string &msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

void StrBlob::pop_back()
{
	check(0, "popback on empty StrBlob");
	data->pop_back();
}

string& StrBlob::front() const
{
	check(0, "front on empty Strblob");
	return data->front();
}

string& StrBlob::back() const
{
	check(0, "back on emptu Strblob");
	return data->back();
}
// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
shared_ptr<vector<string>>  StrBlobPtr::check(size_t i, const string &msg)const
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

string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}


bool operator==(const ConststrBlobPtr& lhs, const ConststrBlobPtr& rhs)
{
	return lhs.curr == rhs.curr;
}

bool operator!=(const ConststrBlobPtr& lhs, const ConststrBlobPtr& rhs)
{
	return !(lhs == rhs);
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

bool operator==(const StrBlob& str1, const StrBlob& str2)
{
	return *str1.data == *str2.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
	lhs.
}