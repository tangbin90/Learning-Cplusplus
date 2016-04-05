#ifndef IF_THEN_ELSE_H
#define IF_THEN_ELSE_H
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ifthenelse
{
public:
	ifthenelse() = default;
	int operator()(int a, int b, int c) const
	{
		if (a > 0)
			return b;
		else
			return c;
	}
};

class ReadString
{
public:
	ReadString(istream &o = cin) :in(o){}
	string operator()(){
		string str="";
		if (in)
			getline(in, str);
		return str;
	}
private:
	istream& in;
};

class isequal{
public:
	isequal(string str = "aaa") :k(str){};
	bool operator()(string a)
	{
		return a == k;
	}
private:
	string k;
};

class equaltosize
{
public:
	equaltosize(int sz = 1) :size(sz){}
	bool operator()(string str){ return str.size() == size; }
	int getsize(){ return size; }
private:
	int size;
};

class comparesize
{
public:
	bool operator()(const string& a, const string& b)
	{
		return a.size() < b.size();
	}
};

class biggersize
{
public:
	biggersize(int size = 0) :sz(size){}
	bool operator()(const string &a)
	{
		return a.size() >= sz;
	}
private:
	int sz;
};

class printstr
{
public:
	printstr(ostream &o=cout, string& dev=string(" ")) :os(o), devide(dev){}
	void operator()(const string& word) const{ os << word << devide; }
private:
	string devide;
	ostream& os;
};

class SmallInt
{
	friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
	SmallInt(int i = 0) :val(i){};
	operator int() const { return val; }
private:
	std::size_t val;
};
SmallInt operator+(const SmallInt& a, const SmallInt& b);

#endif