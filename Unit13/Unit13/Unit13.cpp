// Unit13.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
class Point
{
public:
	Point()
	{
		cout << "construct" << endl;
	}
	Point(Point&)
	{
		cout << "copy construct" << endl;
	}
};
void printvec(vector<int> vec)
{
	cout << *vec.begin() << endl;
}

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0){}
	HasPtr(const HasPtr& hsptr)
	{
		this->i = hsptr.i;
		this->ps = new std::string(*(hsptr.ps));
	}
	HasPtr& operator=(const HasPtr& lf)
	{
		this->i = lf.i;
		std::string *new_ps = new string(*lf.ps);
		delete ps;
		ps = new_ps;
		return *this;
	}
	~HasPtr()
	{
		delete ps;
	}
private:
	std::string *ps;
	int i;
};

struct X
{
	X(){ cout << "X()" << endl; }
	X(const X&){ cout << "X(const X&)" << endl; }
	X& operator=(X& little)
	{
		cout << "operator=(X& little)" << endl;
		return *this;
	}

	~X()
	{
		cout << "~X()" << endl;
	}
};


void func(const X& xk)
{
	X* xporint = new X();
	vector<X> xvector;
	xvector.reserve(2);
	//可能在pushback的时候容量不够
	xvector.push_back(xk);
	xvector.push_back(*xporint);
	delete xporint;
}
Point global;

class numbered
{
public:
	static int num;
	numbered(){ mysn = num++; }
	numbered(const numbered& numer){ cout << "copt construct!" << endl; mysn = num++; }
	int mysn;
};
void f(numbered& s){ cout << s.mysn << endl; }

int numbered::num = 0;

//13.18
class Employee
{
public:
	static int count;
	Employee():name(""),num(count++){ }
	Employee(string nm):name(nm),num(count++){ }
	Employee(const Employee& rh){ num = count++; name = rh.name; }
	Employee& operator=(const Employee& rh){ num = count++; name = rh.name;}
private:
	string name;
	int num;
};
int Employee::count = 0;
int _tmain(int argc, _TCHAR* argv[])
{
	Employee em("tangbin");
	Employee a = em;
	system("pause");
	return 0;
}

