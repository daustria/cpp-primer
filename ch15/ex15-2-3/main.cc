#include <cstddef>
#include <string>
#include <iostream>

//Exercise 15.4
/*
 * class Base { //... };
 *
 * a) class Derived : public Derived { ... };
 * 
 * this is incorrect, a class cannot inherit from itself. if a class
 * inherits from another class, it should know what members it receieves.
 * as a result, this example results in circular logic.
 *
 * b) class Derived : private Base {...};
 *
 * this is fine
 *
 * c)
 *
 * class Derived : public Base;
 *
 * This is incorrect, a class declaration must not include its derivation list.
 * One can think of the derivation list as part of its implementation 
 */

class Quote
{
	public:
		Quote() = default;
		Quote(const std::string &book, double sales_price): bookNo(book), price(sales_price) {}
		std::string isbn() const { return bookNo; }
		virtual double net_price(std::size_t n) const 
		{ 
			std::cout << "Quote's net_price() " << std::endl;
			return price * n; 
		}
		virtual ~Quote() = default; //provide a virtual destructor for inheritance
		//Note: Destructors of base classes must be virtual so that the appropriate destructor
		//is dynamically dispatched when deleting pointers to derived types. 
	private:
		const std::string bookNo;
	protected:
		double price = 0.0;
};

class BulkQuote : public Quote
{
	public:
		BulkQuote() = default;
		BulkQuote(const std::string &book, double sales_price, std::size_t applyDisc, double disc): 
			Quote(book, sales_price), min_qty(applyDisc), discount(disc) {}
		double net_price(std::size_t n) const override 
		{
			std::cout << "BulkQuote net_price()" << std::endl;
			if (n >= min_qty)
				return n*(1-discount)*price;
			else
				return n*price;
		}

//	private:
	protected:
		std::size_t min_qty = 0;
		double discount = 0.0;
};

//Exercise 15.7
class LimitQuote : public BulkQuote
{
	public:
		LimitQuote() = default;
		LimitQuote(const std::string &book, double sales_price, std::size_t applyDisc, double disc, std::size_t stopDisc):
			BulkQuote(book, sales_price, applyDisc, disc), max_qty(stopDisc) {}

		double net_price(std::size_t n) const override
		{
			if (n >= min_qty && n <= max_qty)
				return n*(1-discount)*price;
			else
				return n*price;	
		}

	private:
		std::size_t max_qty;
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
	BulkQuote bq("11010101", 11.23, 5, 0.7);
	LimitQuote lq("21010101", 11.23, 5, 0.7, 10);

	print_total(std::cout, q, 9);
	print_total(std::cout, bq, 11);
	print_total(std::cout, lq, 11);

	// the copy assignment operator of Quote is actually deleted implicitly
	// since it has a constant member, namely bookNo.
//	q = bq; //the bulk quote portion of bq is sliced down


	BulkQuote bq2;
	Quote *p = &bq2; //valid, this is a 'derived to base' conversion.
	p->net_price(0); //this call's BulkQuote's net price.

//	BulkQuote *p_bq = &q; 
//
//	This is invalid. A Quote object doesn't have BulkQuote members.



//	BulkQuote *p_bq = p; 
//
//	This is also invalid for similar reasons. 
//	Note that the dynamic type of p is actually an address to a BulkQuote object. 
//	The static type of p is Quote. The compiler only looks at static types, and thinks
//	we are trying to assign a BulkQuote pointer an address to a Quote object (which
//	is illegal by the previous example). Of course, p is actually a pointer to a 
//	BulkQuote object and this conversion works. We can use casting to override the compiler
//	in this situation.

}

