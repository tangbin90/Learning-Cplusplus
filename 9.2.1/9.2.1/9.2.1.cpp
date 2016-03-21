// 9.2.1.cpp : �������̨Ӧ�ó������ڵ㡣
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
	vector<int> vec0 = { 1, 2, 3, 4 };//��ʼ���б��ʼ��
	vector<int> vec1 = vec0;//������ʼ��
	vector<int> vec2(vec0);//������ʼ��
	vector<int> vec3(vec0.begin(), vec0.end());//��������ʼ��
	vector<int> vec4(3, 0);//ָ����С�������ʻ�
	vector<int> vec5(6);//ָ����С������Ĭ�Ϲ��캯����ʼ��

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

