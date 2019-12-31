#include <vector>

template <typename T>
class Node
{
	public:
		T(T val);
	private:
		T data;
		std::vector<T> children;

};
