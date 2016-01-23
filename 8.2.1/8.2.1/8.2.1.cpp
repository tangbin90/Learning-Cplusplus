// 8.2.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

enum g_Status{valid, invalid};
Sales_data& Sales_data::combine(const Sales_data& salesdata)
{
	units_sold += salesdata.units_sold;
	revenue += salesdata.revenue;
	return *this;
}

double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
Sales_data add(const Sales_data& sd1, const Sales_data& sd2)
{
	Sales_data res = sd1;;
	res = res.combine(sd2);
	return res;

}

istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price* item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

g_Status ReadfileToVector(vector<string> &vecstr, string filename)
{
	ifstream in(filename);
	if (!in.is_open())
	{
		cerr << "Can't find file "<< filename.c_str() <<endl;
		return invalid;
	}
	string temp;
	while (getline(in, temp))
	{
		vecstr.push_back(temp);
	}
	return valid;
}

g_Status ReadWordToVector(vector<string> &vecstr, string filename)
{
	ifstream in(filename);
	if (!in.is_open())
	{
		cerr << "Can't find file " << filename.c_str() << endl;
		return invalid;
	}
	string temp;
	while (in>>temp)
	{
		vecstr.push_back(temp);
	}
	return valid;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<Sales_data> vecSales_data;
	string filename("Sales.txt");
	ifstream in(filename);
	if (!in.is_open())
	{
		cout << "Cant open file " << filename.c_str();
		exit(-1);
	}
	Sales_data salesdata;
	while (read(in, salesdata))
	{
		vecSales_data.push_back(salesdata);
	}

	system("pause");
	return 0;
}

