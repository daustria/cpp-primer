#ifndef PERSON_OBSERVER_H
#define PERSON_OBSERVER_H
#include <iostream>
class PersonObserver : public Observer<Person>
{
	public:
		~PersonObserver() = default;

		void field_changed(Person &source, const std::string &fieldName) override
		{
			std::cout << "Person's " << fieldName << " changed to " << source.getAge() << std::endl;
		}

		bool operator==(const Observer<Person> &obs) override { return this == &obs; }	
};
#endif // PERSON_OBSERVER_H
