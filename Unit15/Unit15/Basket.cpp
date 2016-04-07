#include  "stdafx.h"
#include "Quote.h"
#include "Basket.h"

double Basket::total_receipt(std::ostream &os) const
{
	double sum = 0.0;

	for (auto iter = items.cbegin(); iter != items.cend();
		iter = items.upper_bound(*iter))//跳过与之前相同的所有的书
	{
		sum += print_total(os, **iter, items.count(*iter));
	}                                   // ^^^^^^^^^^^^^ using count to fetch
	os << "Total Sale: " << sum << std::endl;
	return sum;
}