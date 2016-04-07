#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>
using namespace std;

class Quote
{
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :bookNo(book), price(sales_price){}
	virtual Quote* clone() const
	{
		return new Quote(*this);
	}

	virtual Quote* clone()
	{
		return new Quote(std::move(*this));
	}
	Quote(const Quote& quote)
	{
		price = quote.price;
		bookNo = quote.bookNo;
		std::cout << "Quote(const Quote& quote)" << std::endl;

	}

	Quote& operator=(Quote& quote)
	{
		if (this != &quote)
		{
			price = quote.price;
			bookNo = quote.bookNo;
		}
		std::cout << "Quote& operator=(Quote& quote)" << std::endl;
		return *this;
	}

	virtual ~Quote()
	{
		std::cout << "virtual ~Quote()" << std::endl;
	}
	std::string isbn() const { return bookNo; }

	virtual double net_price(std::size_t n) const
	{
		return n*price;
	}

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


	Disc_quote(const Disc_quote& disc) :Quote(disc), qty(disc.qty), discount(disc.discount){ std::cout << "Disc_quote(Disc_quote& disc)" << std::endl; }
	Disc_quote& operator=(Disc_quote& disc)
	{
		if (this != &disc)
		{
			Quote::operator=(disc);
			qty = disc.qty;
			discount = discount;
			std::cout << "Disc_quote& operator=" << std::endl;

		}
		return *this;
	}
	~Disc_quote()
	{
		std::cout << "~Disc_quote()" << std::endl;
	}
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
	Bulk_quote(const Bulk_quote& bulk) :Disc_quote(bulk){ std::cout << "Bulk_quote(Bulk_quote& bulk)" << std::endl; }
	//using Disc_quote::Disc_quote;
	virtual Bulk_quote* clone() const override
	{
		return new Bulk_quote(*this);
	}

	virtual Bulk_quote* clone() override
	{
		return new Bulk_quote(std::move(*this));
	}
	Bulk_quote& operator=(Bulk_quote& bulk)
	{
		if (this != &bulk)
		{
			Disc_quote::operator=(bulk);
		}
		return *this;
	}
	~Bulk_quote()
	{
		std::cout << "~Bulk_quote()" << std::endl;
	}
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
double print_total(std::ostream &os, const Quote &item, std::size_t n);

#endif