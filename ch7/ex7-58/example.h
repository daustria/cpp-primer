#include <vector>
#ifndef EXAMPLE_H
#define EXAMPLE_H
class Example
{
	public:
		//this has to be constexpr for us to provide an inclass initializer--it is not const
		static constexpr double rate = 6.5;
		//we can provide an in class initializer for const integral types.
		static const int vecSize = 20;
		static std::vector<double> vec(vecSize);

};
#endif //EXAMPLE_H
