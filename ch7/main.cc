#include "salesdata.h"
#include <iostream>

using namespace std;

int main()
{
	Sales_data total;

	cout << "Enter a book" << endl;
	if (read(cin, total))
	{
		Sales_data trans;
		while(read(cin, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	} else {
		cerr << "No data" << endl;
	}



}
