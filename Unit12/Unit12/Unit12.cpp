
//
//  ex12_20.cpp
//  Exercise 12.20
//
//  Created by pezy on 12/26/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Write a program that reads an input file a line at a time into
//  a StrBlob and uses a StrBlobPtr to print each element in that StrBlob.
#include "stdafx.h"
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
char* connectstr(const char* str1, const char* str2)
{
	char *newstr = new char[255]();
	strcat(newstr, str1);
	strcat(newstr, str2);
	return newstr;
}

int main()
{
	int n = 10;
	vector<int> vi({ 221, 2, 34, 5, 6 });
	int* pchar = new int[n]{1,2,3,4,5,6,7,8,9,0};
	allocator<int> alloc;
	auto p = alloc.allocate(sizeof(int)*10);

	auto q = uninitialized_copy(vi.begin(), vi.end(), pchar);

	cout << pchar[0] << endl;
}