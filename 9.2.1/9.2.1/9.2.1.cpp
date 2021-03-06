// 9.2.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <iostream>
#include <deque>
using namespace std;

bool findN(vector<int>::iterator begin, vector<int>::iterator end, int N)
{
	if (begin >= end)
		return false;
	for (vector<int>::iterator iter = begin; iter != end; iter++)
	{
		if (*iter == N)
			return true;
	}
	return false;
}

vector<int>::iterator findN1(vector<int>::iterator begin, vector<int>::iterator end, int N)
{
	if (begin >= end)
		return end;
	for (vector<int>::iterator iter = begin; iter != end; iter++)
	{
		if (*iter == N)
			return iter;
	}
	return end;
}

bool vectorcompare(vector<int> vec1, vector<int> vec2)
{
	return vec1 == vec2;
}

bool listvectorcompare(vector<int> vec, list<int> lst)
{
	vector<int> temp;
	temp.assign(lst.begin(), lst.end());

	return temp == vec;
}

void copytodeque(list<int> &intlist, deque<int> &evende, deque<int> &oddde)
{
	for (list<int>::iterator iter = intlist.begin(); iter != intlist.end(); iter++)
	{
		if (*iter & 0x01 != 0)
		{
			oddde.push_back(*iter);
		}
		else
		{
			evende.push_back(*iter);
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec0 = { 1, 2, 3, 4 };//初始化列表初始化
	vector<int> vec1 = vec0;//拷贝初始化
	vector<int> vec2(vec0);//拷贝初始化
	vector<int> vec3(vec0.begin(), vec0.end());//迭代器初始化
	vector<int> vec4(3, 0);//指定大小参数舒适化
	vector<int> vec5(6);//指定大小参数加默认构造函数初始化

	list<int> lst = { 1, 2, 3, 4, 5, 6 };
	int i = 2;
	vector<double> vecdouble(6,i);
	vecdouble.assign(lst.begin(),lst.end());
	for (vector<double>::iterator iter = vecdouble.begin(); iter != vecdouble.end(); iter++)
	{
		cout << *iter << endl;;
	}

	list<char*> listvalue{ "asdf", "vssd", "qqqq" };
	vector<string> vecstring;
	vecstring.assign(listvalue.begin(), listvalue.end());
	vector<string>::const_iterator iter = vecstring.begin();
	cout << *iter << endl;

	list<string> sdeq;
	string temp;
	while (cin >> temp)
	{
		sdeq.push_back(temp);
	}

	for (list<string>::iterator iter = sdeq.begin(); iter != sdeq.end(); iter++)
	{
		cout << *iter << endl;
	}

	list<int> intls = { 1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 9, 7, 5, 4, 43 };
	deque<int> oddde, evende;
	copytodeque(intls, evende, oddde);
	
	system("pause");
	return 0;
}

