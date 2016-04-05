// Unit14.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include "Sales_data.h"
#include "String.h"
#include <vector>
#include <iostream>
#include "Blob.h"
#include "if_then_else.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <map>
#include <functional>

int add(int i, int j)
{
	return i + j;
}

struct divide
{
	int operator()(int denominator, int divisor)
	{
		return denominator / divisor;
	}

};

SmallInt operator+(const SmallInt& a, const SmallInt& b)
{
	SmallInt result;
	result.val = a.val + b.val;
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*ifstream file("read.txt");
	string line;
	int size[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<equaltosize> equalvec;

	for (auto i : size)
	{
		equalvec.push_back(equaltosize(i));
	}
	
	map<int,int> mapstr;
	for (auto i:size)
		mapstr[i] = 0;
	while (getline(file, line))
	{
		string word;
		istringstream str(line);
		while (str >> word)
		{
			for (auto is_equal_to : equalvec)
			{
				if (is_equal_to(word))
					++mapstr[is_equal_to.getsize()];
			}
		}
	}

	for (auto pair : mapstr)
		std::cout << "count in"<< pair.first << " : " << pair.second << std::endl;
	using namespace placeholders;
*/
	/*map<string, function<int(int, int)>> binops = 
	{
		{ "+", add },
		{ "-", std::minus<int>() },
		{ "*", [](int i, int j){return i*j; } },
		{"/",divide()},
		{ "%", [](int i, int j){return i%j; } }
	};
	std::cout << "Pls enter as: num operator num :\n";
	int lhs, rhs; std::string op;
	while (cin >> lhs >> op >> rhs)
	{
		std::cout << binops[op](lhs, rhs) << std::endl;
		std::cout << "Pls enter as: num operator num :\n" ;
	}*/
	SmallInt s1;
	double d =s1 + SmallInt(3.14);
	cout << d;
	system("pause");
	return 0;
}

