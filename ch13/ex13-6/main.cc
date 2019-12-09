#include <string>

//Exercise 13.6
/*The copy assignment operator invokes the copy assignment constructor. It is used whenever
 * a class is initialized with the assignment operator where the right hand operand is another instance of the class.
 * The copy assignment constructor, like the copy constructor, is synthesized whenever the class does not provide one.
 */



//Exercise 13.8


class HasPtr
{
	public: 
	
		
		HasPtr(const std::string &s = std::string()):
			ps(new std::string(s)), i(0):
		{
			
		}

		HasPtr &operator=(const HasPtr &rhs):
			ps = new std::string(*(rhs.ps));
			i = rhs.i;

	private:
		std::string *ps;
		int i;
};

int main()
{
	std::string s{"hello"};
	HasPtr hp{s};
	HasPtr hp2 = hp; //initialize with copy assignment operator

}


