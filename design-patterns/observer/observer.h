#ifndef OBSERVER_H
#define OBSERVER_H
#include <string>
template<typename T> class Observer
{
	public:
		virtual ~Observer() = default;
		virtual void field_changed(T &source, const std::string &fieldName) = 0;
		virtual bool operator==(const Observer<T> &) = 0;
};
#endif //OBSERVER_H
