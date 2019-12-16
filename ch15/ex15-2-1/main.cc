#include <cstddef>
#include <string>
#include <iostream>

//Exercise 15.1
/*
 * A virtual member is a member of a class for which derived classes are expected
 * to define for themselves. This is done using the keyword 'override'
 */

//Exercise 15.2
/*
 * Instances of derived classes have access to protected members of its base class,
 * but not its private members. Interactions between instances of derived classes
 * and members of the base class under the private specification is no different than
 * interactions between the base class and ordinary users.
 */

//Exercise 15.3

class Quote
{
	public:
		Quote() = default;
		Quote(const std::string &book, double sales_price): bookNo(book), price(sales_price) {}
		std::string isbn() const { return bookNo; }
		virtual double net_price(std::size_t n) const { return price * n; }
		virtual ~Quote() = default; //provide a virtual destructor for inheritance
	private:
		const std::string bookNo;
	protected:
		double price = 0.0;
};

double print_total(std::ostream &out, const Quote &q, std::size_t n)
{
	double price = q.net_price(n);
	out << "isbn: " << q.isbn() << " price: " << price << std::endl;
	return price;
}

int main()
{
	Quote q("010101101", 23.57);
	print_total(std::cout, q, 9);
}

