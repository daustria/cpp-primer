#include <vector>

template <typename T> class Blob
{
	public:
		typedef T value_type; 
		typedef typename std::vector<T>::size_type size_type;


		//constructors
		Blob();
		Blob(std::initializer_list<T> il);

		//number of elements in the Blob
		size_type size() const { return data->size(); }

		bool empty() const { return data->empty(); }

		//add and remove elements
		void push_back(const T &t) { data->push_back(t); }

		// move version
		void push_back(T &&t) { data->push_back(std::move(t)) }

		void pop_back();

		//element access

		T &back();
		T &operator[] (size_type i);

	private:
		std::shared_ptr<std::vector<T>> data;


		//throw msg if data[i] is not valid
		void check(size_type i, constd std::string &msg) const;
	
}
