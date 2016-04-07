#include "stdafx.h"
#include "Quote.h"

double Bulk_quote::net_price(std::size_t num) const
{
	if (num >= qty)
	{
		return num*price*(1 - discount);
	}
	else
	{
		return num*price;
	}
}

double BulkLimit_quote::net_price(std::size_t num) const
{
	if (num <= qty)
	{
		return num*price*(1 - discount);
	}
	else
	{
		return num*price;
	}
}
        
double print_total(std::ostream &os, const Quote &item, size_t n)
{
	// depending on the type of the object bound to the item parameter
	// calls either Quote::net_price or Bulk_quote::net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() // calls Quote::isbn
		<< " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}