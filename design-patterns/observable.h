#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <vector>
#include <string>
#include "observer.h"
template <typename T> 
class Observable
{
	public:
		virtual ~Observable() = default;
		void notify(T &source, const std::string &name) 
		{
			for (auto obs : observers)
				obs->field_changed(source, name);
		}
		void suscribe(Observer<T> *o) { observers.push_back(o); }
		void unsuscribe(Observer<T> *o) 
		{
			for(auto it = observers.begin(); it != observers.end(); ++it)
				if (*it == *o)
				{
					std::iter_swap(it, observers.end() - 1);
					observers.pop_back();
				}
		}

	private:
		std::vector<Observer<T> *> observers;
};
#endif //OBSERVABLE_H
