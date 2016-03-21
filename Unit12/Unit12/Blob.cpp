//
//  ex12_19.cpp
//  Exercise 12.19
//
//  Created by pezy on 12/26/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Define your own version of StrBlobPtr and
//  update your StrBlob class with the appropriate friend declaration and begin
//  and end members.
//
//  @See    ex12_19.h
#include "stdafx.h"
#include "Blob.h"
StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
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
// TODO:  在此处引用程序需要的其他头文件
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

bool StrBlobPtr::operator != (const StrBlobPtr& p) { return p.curr != curr; }

