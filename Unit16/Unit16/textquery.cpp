// textquery.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "TextQuery.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

QueryResult TextQuery::query(const string word)const
{
	static shared_ptr<set<int>> nodata(new set<int>);
	auto loc = wordline.find(word);
	if (loc == wordline.end())
		return QueryResult(word, sp, nodata);
	else
		return QueryResult(word, sp, loc->second);
}
ostream& print(ostream& os, const QueryResult& qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " " << ((qr.lines->size() == 1) ? "time" : "times")<< endl;
	for (auto num : *(qr.lines))
	{
		auto data = (qr.file)->at(num-1);
		os << "\t(line" << num << ")" << data << endl;
	}
	return os;
}
void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	do
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	} while (true);
}


