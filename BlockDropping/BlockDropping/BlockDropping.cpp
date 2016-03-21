// BlockDropping.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <list>
#include <forward_list>
#include <string>
#include <stack>
using namespace std;

class Calender
{
public:
	Calender(unsigned int yearin, unsigned int monthin, unsigned int dayin) :year(yearin), month(monthin), day(dayin){}
	Calender(string date);
	void print(void)
	{
		cout << "year:" << year << endl;
		cout << "month:" << month << endl;
		cout << "day:" << day << endl;

	}
private:
	unsigned int year;
	unsigned int month;
	unsigned int day;
};

Calender::Calender(string date)
{
	string months[] = { "KKK", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	string num = "1234567890";
	string mark = " ,/";
	string::size_type pos = 0;
	if (date.find_first_of(num) == 0)
	{
		pos=date.find_first_of(mark);
		month = stoi(date);
	}
	else
	{
		for (int i = 1; i <= 12; i++)
		{
			if (date.find(months[i]) != string::npos)
			{
				month = i;
				break;
			}
		}
	}

	pos = date.find_first_of(num,pos);
	day = stoi(date.substr(pos));

	pos = date.find_first_of(mark, pos);
	year = stoi(date.substr(pos+1));
}
void FindStringInsertString(forward_list<string>& strlist, string strtofind, string strtoinsert)
{
	forward_list<string>::iterator current = strlist.begin();
	forward_list<string>::iterator pre = strlist.before_begin();
	bool findflag = false;
	while (current != strlist.end())
	{
		if (*current == strtofind)
		{
			current = strlist.insert_after(current,strtoinsert);
			findflag = true;
		}
		pre = current;
		current++;
	}
	
	if (!findflag)
	{
		strlist.insert_after(pre, strtoinsert);
	}
	return;
}
void replacestr(string s, string oldVal, string newVal)
{
	for (int i = 0; i <= s.size() - oldVal.size();)
	{
		if (oldVal == s.substr(i,oldVal.size()))
		{
			s.replace(i, oldVal.size(), newVal);
			i += newVal.size();
		}
		else
			i++;
	}
	cout << s;
}

string addpreafter(string name, string pre, string app)
{
	name.insert(0, pre);
	name.insert(name.size(),app);
	return name;
}

string findwordnotupdown(string word)
{
	string upperdown = "bdfhklgjpqy";
	string::size_type pre = 0;
	string::size_type after = 0;
	string result;
	while(( pre = word.find_first_not_of(upperdown,after)) != string::npos)
	{
		string temp = "";
		after = word.find_first_of(upperdown, pre);
		if (after != string::npos)
		{
			 temp = word.substr(pre, after - pre);
		}
		else
		{
			 temp = word.substr(pre);
		}

		if (temp.size() > result.size())
		{
			result = temp;
		}
	}
	return result;
}

float addvector(vector<string> strvec)
{
	float count = 0;
	for (vector<string>::iterator iter = strvec.begin(); iter != strvec.end(); iter++)
	{
		count += stof(*iter);
	}
	return count;
}


int _tmain(int argc, _TCHAR* argv[])
{
	string input = "this is tangbin((tangbin))with a t and b";
	stack<char> chstack;
	int count = 0;
	for (auto ch : input)
	{
		chstack.push(ch);
		if (ch == '(')
			count++;
		if (count && ch == ')')
		{
			while (chstack.top() != '(')chstack.pop();
			chstack.pop();
			chstack.push('#');
			count--;
		}
	}
	string output;
	while (!chstack.empty())
	{
		output.insert(output.begin(), chstack.top());
		chstack.pop();
	}
	cout << output << endl;
	system("pause");
	return 0;
}

