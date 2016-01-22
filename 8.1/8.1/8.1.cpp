// 8.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

istream& readstream(istream& cstream)
{
	char ch;
	while (cstream>>ch)
	{
		cout << ch;
	}
	return cstream;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int val;
	readstream(cin);
	system("pause");
	return 0;
}

