// 8.3.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

istream& print(istream& in)
{
	char temp;
	while (in >> temp)
	{
		cout << temp;
	}
	in.clear();
	return in;
}
//8.10
vector<string>& filetovector(vector<string>& vecstr, string filename)
{
	ifstream in(filename);
	if (!in.is_open())
	{
		cout << "No such file" << endl;
		exit(-1);
	}

	string temp;
	while (getline(in, temp))
	{
		vecstr.push_back(temp);
	}
	in.clear();
	return vecstr;
}
//8.11
struct PersonInfo
{
	string name;
	vector<string> phones;
};
void PersonInfoRecord(void)
{

	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while (getline(cin, line))
	{
		PersonInfo info;
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
		record.clear();
	}

	for (auto per : people)
	{
		cout << per.name<<endl;
		for (string temp : per.phones)
			cout << temp << " ";
		cout << endl;
	}
}
//8.12
//vector的特性决定了，vector初始化的值是不定的，此时如果初始化了其结果反而不对。
//8.13
bool valid(string nums)
{
	return true;
}

string format(string nums)
{
	return nums;
}

void checknum(ostream os, vector<PersonInfo>& people)
{
	for (const auto &entry : people)
	{
		ostringstream formatted, badnums;
		for (const auto &nums : entry.phones)
		{
			if (!valid(nums))
			{
				badnums << " " << nums;
			}
			else
			{
				formatted << " " << format(nums);
			}


			if (badnums.str().empty())
			{
				os << entry.name << " " << formatted.str() << endl;
			}
			else
			{
				cerr << "input error: " << entry.name << " invalid numbers " << badnums.str() << endl;
			}
		}
	}
}

void PersonInfoRecord2(void)
{

	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	string filename("stdafx.cpp");
	ifstream in(filename);
	if (!in.is_open())
		return;
	while (getline(in, line))
	{
		PersonInfo info;
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
		record.clear();
	}

	for (auto per : people)
	{
		cout << per.name << endl;
		for (string temp : per.phones)
			cout << temp << " ";
		cout << endl;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	/*//8.10
	string filename("stdafx.cpp");
	vector<string> vecstr;
	istringstream stream;
	string word;
	filetovector(vecstr, filename);
	vector<string>::iterator iter;

	for (iter = vecstr.begin(); iter != vecstr.end(); ++iter)
	{
		istringstream record(*iter);
		while (record >> word)
		{
			cout << word << " ";
		}
		cout << endl;
	}*/
	PersonInfoRecord();

	system("pause");
	return 0;
}

