#ifndef QUOTE_H
#define QUOTE_H
#include <iostream>
#include <string>

class Quote
{
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :bookNo(book), price(sales_price){}
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const
	{
		return n*price;
	}
	virtual ~Quote() = default;
	virtual void debug() const
	{
		std::cout << "Base Class:" << std::endl;
		std::cout << "price:" << price << std::endl;
		std::cout << "bookNo" << bookNo <<std:: endl;
	}
protected:
	double price = 0.0;
private:
	std::string bookNo;
};

class Disc_quote :public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string& isbn, double price, std::size_t num, double dis) :
		Quote(isbn, price), qty(num), discount(dis){}

	void debug() const override
	{
		Quote::debug();
		std::cout << "min_qty:" << qty << std::endl;
		std::cout << "discount" << discount << std::endl;
	}
	double net_price(std::size_t n) const = 0;
protected:
	size_t qty;
	double discount = 0.0;

};
class Bulk_quote :public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& isbn, double price, std::size_t min, double dis) :
		Disc_quote(isbn, price,min, dis){}
	double net_price(std::size_t num) const override;
	void debug() const override
	{
		Disc_quote::debug();
	}
};


class BulkLimit_quote :public Disc_quote
{
public:
	BulkLimit_quote() = default;
	BulkLimit_quote(const std::string& isbn, double price, std::size_t max, double dis) :
		Disc_quote(isbn, price, max, dis){}
	double net_price(std::size_t num) const final override;

};
#endif