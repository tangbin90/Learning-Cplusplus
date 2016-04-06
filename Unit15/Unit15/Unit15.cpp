// Unit15.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Quote.h"
#include <string>

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << "# sold: " << n << " total due:" << ret << std::endl;
	return ret;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Bulk_quote bulk("asdfadf",10,10,0.5);
	print_total(std::cout, bulk, 20);
	bulk.debug();
	system("pause");
	return 0;
}

