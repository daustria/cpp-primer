#include <string>

class Hasptr
{
	public:
		HasPtr(const std::string &s = std::String()):
			ps(new std::string(s), i(0), use(new std::size_t(1)) 
	{}

	private:
		std::string *ps;
		int i;
		std::size_t *use;


}
