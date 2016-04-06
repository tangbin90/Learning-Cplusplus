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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  