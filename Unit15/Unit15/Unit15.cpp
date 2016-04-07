// Unit15.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Quote.h"
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "quote.h"
#include "Basket.h"
using namespace std;
// just for 2D shape
class Shape
{
public:
	typedef std::pair<double, double>    Coordinate;

	Shape() = default;
	Shape(const std::string& n) :
		name(n) { }

	virtual double area()       const = 0;
	virtual double perimeter()  const = 0;

	virtual ~Shape() = default;
private:
	std::string name;
};

class Rectangle : public Shape
{
public:
	Rectangle() = default;
	Rectangle(const std::string& n,
		const Coordinate& a,
		const Coordinate& b,
		const Coordinate& c,
		const Coordinate& d) :
		Shape(n), a(a), b(b), c(c), d(d) { }

	~Rectangle() = default;

protected:
	Coordinate  a;
	Coordinate  b;
	Coordinate  c;
	Coordinate  d;
};

class Square : public Rectangle
{
public:
	Square() = default;
	Square(const std::string& n,
		const Coordinate& a,
		const Coordinate& b,
		const Coordinate& c,
		const Coordinate& d) :
		Rectangle(n, a, b, c, d) { }

	~Square() = default;
};

int _tmain(int argc, _TCHAR* argv[])
{
	Bulk_quote bq("aaaaaaaaaa", 10.0, 20, 0.7);
	Bulk_quote bb = bq;
	Bulk_quote bq1("bbbbbbbbb", 15.0, 20, 0.7);
	Basket bas;
	bas.add_item(bq);
	bas.add_item(bq1);
	bas.add_item(bb);
	bas.total_receipt(cout);
	system("pause");
	return 0;
}

