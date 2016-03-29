// String.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "String.h"
#include <algorithm>
#include <memory>
#include <iostream>
#include <vector>
void String::reallocate()
{
	auto newcapacity = size() ? size() * 2 : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto ele = elements;
	for (size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++, *ele++);
	}
	free();
	elements = newdata;
	firstfree = dest;
	cap = newdata + newcapacity;
}

void String::free()
{
	if (elements)
	{
		std::for_each(elements, firstfree, [this](char& a){this->alloc.destroy(&a); });
		alloc.deallocate(elements, cap - elements);
	}

}

std::pair<char*, char*> String::alloc_n_copy(const char* begin, const char* end)
{

	auto data = alloc.allocate(end - begin);
	return{ data, std::uninitialized_copy(begin, end, data) };
}

String::~String()
{
	free();
}

String::String(const char* begin)
{
	int length = strlen(begin);
	char* end = const_cast<char*>(begin)+length+1;
	auto data = alloc_n_copy(begin, end);
	elements = data.first;
	firstfree = cap = data.second;
}

String::String(const String& str)
{
	auto newdata = alloc_n_copy(str.begin(), str.end());
	elements = newdata.first;
	firstfree = cap = newdata.second;
	std::cout << "copy construct" << std::endl;
}

String& String::operator=(String& str)
{
	auto newdata = alloc_n_copy(str.begin(), str.end());
	free();
	elements = newdata.first;
	firstfree = cap = newdata.second;
	std::cout << "Operator=" << std::endl;
	return *this;
}

String::String(String&& str) _NOEXCEPT:elements(str.elements), firstfree(str.firstfree), cap(str.cap)
{
	str.elements = str.firstfree = str.cap = nullptr;
}

String& String::operator=(String&& str)_NOEXCEPT
{
	if (this != &str)
	{
		free();
		elements = str.elements;
		cap = str.cap;
		firstfree = str.firstfree;
		str.elements = str.cap = str.firstfree = nullptr;
	}
	return *this;
}

bool operator==(String& str1, String& str2)
{
	const char* c = str1.c_str();
	const char* s = str2.c_str();
	if (str1.size() != str2.size())
		return false;

	while (*c)
	{
		if (*c++ != *s++)
			return false;
	}
	return true;
}

bool operator!=(String& str1, String& str2)
{
	return !(str1 == str2);
}

std::ostream& operator<<(std::ostream& out, const String& str)
{
	const char* c = str.c_str();
	while (*c)
		out << *c++;
	out << std::endl;
	return out;
}
String baz()
{
	String ret("world");
	return ret; // first avoided
}
int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<String> vecstr;
	String str1("tangbin");
	String str2("tangbin");
	if (str1 == str2)
		std::cout << "same" << std::endl;

	vecstr.push_back(str2);
	vecstr.push_back(str1);
	String s5 = baz(); // second avoided
	//vecstr.push_back(str2);
	//vecstr.push_back(str3);
	system("pause");
	return 0;
}

