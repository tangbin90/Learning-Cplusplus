#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <memory>
#include "Vec.h"
#include "debugdelete.h"

using namespace std;
typedef Vec<string> StrVec;
class QueryResult;
class TextQuery
{
	friend QueryResult;
public:
	TextQuery(std::ifstream &in) :sp(new StrVec(),DebugDelete())
	{
		std::string line;
		int countline = 1;
		while (std::getline(in, line))
		{
			sp->push_back(line);
			std::istringstream stream(line);
			std::string word;
			while (stream >> word)
			{
				word.erase(std::remove_if(word.begin(), word.end(), ispunct),word.end());
				auto &lines = wordline[word];
				if (!lines)
				{
					lines.reset(new set<int>());
				}
				lines->insert(countline);
			}
			countline++;
		}
	}

	QueryResult query(const string word)const;
private:
	shared_ptr<StrVec> sp;
	map<string, shared_ptr<set<int>>> wordline;
};

class QueryResult
{
	friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<StrVec> sp, shared_ptr<set<int>> line) :sought(s), lines(line), file(sp)
	{}
	set<int>::iterator begin()
	{
		return lines->begin();
	}

	set<int>::iterator end()
	{
		return lines->end();
	}
	shared_ptr<StrVec> get_file()
	{
		return file;
	}
private:
	string sought;
	shared_ptr<set<int>> lines;
	shared_ptr<StrVec> file;
};

void runQueries(ifstream &infile);