// Unit14.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Sales_data.h"
#include "String.h"
#include <vector>
#include <iostream>
#include "Blob.h"

int _tmain(int argc, _TCHAR* argv[])
{
	String str1("this is tangbin");
	String str2("bingo");
	std::cout << str1[0] << std::endl;

	StrBlobPtr sb1{ "a", "b", "c" };
	cout << sb1[2]<<endl;
	system("pause");
	return 0;
}

