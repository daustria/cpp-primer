#include <string>
#include <iostream>
#include "salesdata.h"
using namespace std;

string Sales_data::isbn() const {
	return bookNo;
}

double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue/units_sold;
	else
		return 0;
}

Sales_data & Sales_data::combine(const Sales_data & other)
{
	units_sold += other.units_sold;
	revenue += other.revenue;
	return *this;
}

istream & read(istream &in, Sales_data &s)
{
	in >> s.bookNo >> s.units_sold >> s.revenue;
	return in;
} 

ostream & print(ostream &out, Sales_data const &s)
{
	out << s.bookNo << s.units_sold << s.revenue;
	return out;
}
