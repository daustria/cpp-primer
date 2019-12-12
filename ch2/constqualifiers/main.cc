int main()
{
	int i = 7;
	const double pi = 3.14;

	// the type of pi can be converted to the type of the reference x.
	const int &x = pi;

	// similarly for y.
	const int &y = 23;

	// invalid. a reference to non const cannot be initialized with an rvalue.
	// int &y2 = 23;


}
