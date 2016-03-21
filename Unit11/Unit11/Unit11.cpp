// Unit11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <algorithm>
#include <utility>
#include <sstream>
#include <fstream>
#include <unordered_map>
using namespace std;

unordered_map<string, string> buildMap(ifstream &map_file)
{
	unordered_map<string, string> mapstr;
	string key, value;
	while (map_file >> key && getline(map_file, value))
	{
		if (value.size() > 1)//考虑到空格
		{
			mapstr[key] = value.substr(1).substr(0,value.find_last_not_of(" "));
		}
		else
			throw runtime_error("no rule for " + key);
	}

	return mapstr;
}

const string & transform(const string &s, const unordered_map<string, string> &m)
{
	auto map_it = m.find(s);
	if (map_it != m.cend())
	{
		return map_it->second;
	}
	else
	{
		return s;
	}
}
void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text))
	{
		string word;
		istringstream strstream(text);
		while (strstream >> word)
		{
			cout << transform(word, trans_map) << " ";
		}
		cout << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> strvec;
	{
		vector<string> v2 = { "string", "is", "this" };
		strvec = v2;
	}
	cout << strvec.size() << endl;
}
	 


