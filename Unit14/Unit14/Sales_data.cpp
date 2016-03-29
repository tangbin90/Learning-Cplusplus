#include "stdafx.h"
#include "Sales_data.h"

Sales_data::Sales_data(std::istream &is)
{
	is >> *this;
}
std::istream& operator>>(std::istream& in, Sales_data& sales)
{
	//in >> sales.bookNo >> sales.units_sold >> sales.revenue;
	//if (!in)
	//{
	//	sales = Sales_data();
	//}
	//return in;

	double price;
	in >> sales.bookNo >> sales.units_sold >> price;
	sales.revenue = sales.units_sold * price;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Sales_data& sales)
{
	out << sales.bookNo <<" "<< sales.units_sold <<" "<< sales.revenue;
	return out;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data result;
	result.units_sold=lhs.units_sold + rhs.units_sold;
	result.revenue = lhs.revenue + rhs.revenue;
	return result;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}