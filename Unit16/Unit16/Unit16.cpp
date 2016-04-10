// Unit16.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Sales_item.h"
#include <vector>
#include <set>
#include <string>

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


//template<typename T, unsigned size>
//constexpr unsigned getSize(const T(&)[size])
//{
//	return size;
//}

int _tmain(int argc, _TCHAR* argv[])
{
	string arr[] = { "asdfasdf", "vvvvv", "aaaaa", "dddd" };
	cout << *begin(arr) << endl << *(end(arr) - 1) << endl;
	system("pause");
	return 0;
}

