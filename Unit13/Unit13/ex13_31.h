//
//  ex13_31.h
//  Exercise 13.31 
//
//  Created by pezy on 1/23/15.
//
//  Give your class a < operator and define a vector of HasPtrs. 
//  Give that vector some elements and then sort the vector. 
//  Note when swap is called.
//
//  Refactored by Yue Wang Jul 2015
//

#ifndef CP5_ex13_11_h
#define CP5_ex13_11_h

#include <string>
#include <iostream>

class HasPtr
{
public:
	friend void swap(HasPtr& lhs, HasPtr& rhs);

	HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0){}
	HasPtr(const HasPtr& hsptr)
	{
		this->i = hsptr.i;
		this->ps = new std::string(*hsptr.ps);
	}

	HasPtr& operator=(HasPtr& lf)
	{
		std::string* new_ps = new std::string(*lf.ps);
		delete ps;
		ps = new_ps;
		i = lf.i;
		return *this;
	}


	void show() const
	{
		std::cout << *ps << std::endl;
	}
	bool operator<(const HasPtr &rhs)
	{
		return *ps < *rhs.ps;
	}
	~HasPtr()
	{
		delete ps;
	}

private:
	std::string *ps;
	int i;
};
inline void swap(HasPtr& lhs, HasPtr& rhs)
{
	std:: cout << "outside swap" << std::endl;
	using std::swap;
	swap(lhs.i, rhs.i);
	swap(lhs.ps, rhs.ps);
	std::cout << "swap" << std::endl;
}


#endif