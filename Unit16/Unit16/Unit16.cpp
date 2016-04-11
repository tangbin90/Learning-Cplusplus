// Unit16.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Sales_item.h"
#include <vector>
#include <set>
#include <string>
#include "Blob.h"
#include "Vec.h"
#include "debugdelete.h"
#include "Textquery.h"
using namespace std;

template<typename T>
int compare(const T &t1, const T &t2)
{
	if (t1>t2) return 1;
	if (t1<t2) return -1;
	return 0;
}

template<typename T, typename value>
T& find(const T& begin,const T& end, value& i)
{
	for (auto temp = begin; temo != end;temp++)
	{
		if (*temp == i)
			return temp;
	}
	return end;
}

template<typename ARR>
void print(ARR const &arr)
{
	for (auto const& ele : arr)
	{
		cout << ele << std::endl;
	}
	return;
}

template<typename T, unsigned sz>
T* begin(const T (&arr)[sz])
{
	return arr;
}

template<typename T, unsigned sz>
T* end(const T(&arr)[sz])
{
	return arr+sz;
}

template <typename Container>
std::ostream& print(const Container& constainer, std::ostream& os)
{
	for (typename Container::size_type i = 0; i != Container.size(); ++i)
	{
		os << constainer[i] << " ";
	}
	return os;
}

template <typename Container>
std::ostream& print1(const Container& constainer, std::ostream& os)
{
	for (typename Container::const_iterator i = constainer.cbegin(); i != constainer.cend(); ++i)
	{
		os << *i << " ";
	}
	return os;
}

int _tmain(int argc, _TCHAR* argv[])
{
	runQueries(ifstream("Alice.txt"));
	system("pause");
	return 0;
}

